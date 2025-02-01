#include "Systems/Impl/RenderCollidersSystem.h"

#include "defs.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Position.h"

void RenderCollidersSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Collider, const Position>(__func__)
            .kind(flecs::OnStore)
            .each([](const Collider &collider, const Position &position) {
                static auto showColliders = false;
                if (IsKeyPressed(KEY_GRAVE)) showColliders = !showColliders;
                if (showColliders) {
                    DrawCircleLines(toInt(position.position.x), toInt(position.position.y), collider.radius, GREEN);
                }
            });
}
