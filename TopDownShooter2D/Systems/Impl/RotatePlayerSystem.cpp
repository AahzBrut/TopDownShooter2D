#include "Systems/Impl/RotatePlayerSystem.h"

#include <raylib.h>
#include <raymath.h>

#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"


void RotatePlayerSystem(const flecs::world &ecsWorld) {
    const auto camera = ecsWorld.get<Camera2D>();

    ecsWorld.system<const Position, Rotation>(__func__)
            .with<Player>()
            .each([camera](const Position &position, Rotation &rotation) {
                const auto mousePosition = GetScreenToWorld2D(GetMousePosition(), *camera);
                const auto mouseDirection = Vector2Normalize(Vector2Subtract(mousePosition, position.position));
                rotation.rotation = Vector2Angle(Vector2(0.f, -1.f), mouseDirection) * RAD2DEG;
            });
}
