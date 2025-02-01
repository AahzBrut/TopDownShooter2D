#pragma once
#include <flecs.h>

#include "Components/Impl/Collider.h"

inline void RenderCollidersSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Collider>(__func__)
            .kind(flecs::OnStore)
            .each([](const Collider &collider) {
                static auto showColliders = false;
                if (IsKeyPressed(KEY_GRAVE)) showColliders = !showColliders;
                if (showColliders) {
                    DrawCircleLines(toInt(collider.center.x), toInt(collider.center.y), collider.radius, GREEN);
                }
            });
}
