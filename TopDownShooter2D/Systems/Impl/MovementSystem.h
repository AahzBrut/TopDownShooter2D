#pragma once
#include <flecs.h>

#include "raymath.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Velocity.h"


inline void MovementSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<Position, const Velocity>()
        .each([](Position &position, const Velocity &velocity) {
            position.position = Vector2Add(position.position, velocity.velocity);
    });
}
