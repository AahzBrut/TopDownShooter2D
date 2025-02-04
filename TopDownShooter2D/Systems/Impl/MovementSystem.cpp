#include "Systems/Impl/MovementSystem.h"

#include <raylib.h>
#include <raymath.h>

#include "defs.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Velocity.h"


void MovementSystem(const flecs::world &ecsWorld) {
    const auto camera = ecsWorld.get_mut<Camera2D>();

    ecsWorld.system<Position, const Velocity>(__func__)
            .each([camera](const flecs::iter &it, const size_t row, Position &position,
                           const Velocity &velocity) {
                const auto deltaTime = it.delta_time();
                const auto newPosition = position.position + velocity.velocity * deltaTime;

                if (it.entity(row).has<Player>()) {
                    const auto posX = newPosition.x < 0
                                          ? 0
                                          : newPosition.x > WINDOW_WIDTH
                                                ? WINDOW_WIDTH
                                                : newPosition.x;
                    const auto posY = newPosition.y < 0
                                          ? 0
                                          : newPosition.y > WINDOW_HEIGHT
                                                ? WINDOW_HEIGHT
                                                : newPosition.y;
                    position.position = Vector2{posX, posY};
                    camera->target = Vector2{posX, posY};
                    camera->offset = Vector2{toFloat(WINDOW_WIDTH) / 2, toFloat(WINDOW_HEIGHT) / 2};
                } else {
                    position.position = newPosition;
                }
            });
}
