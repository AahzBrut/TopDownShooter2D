#pragma once
#include <flecs.h>


inline void SyncCollidersSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Position, Collider>(__func__)
            .each([](const Position &position, Collider &collider) {
            collider.center = position.position;
    });
}
