#pragma once
#include <flecs.h>

#include "Components/Impl/Collider.h"

inline void RenderCollidersSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Collider>()
            .kind(flecs::OnStore)
            .each([](const Collider &collider) {
                DrawCircleLines(toInt(collider.center.x), toInt(collider.center.y), collider.radius, GREEN);
            });
}

