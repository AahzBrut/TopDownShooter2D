#pragma once
#include <flecs.h>

#include "raymath.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Velocity.h"


inline void MovementSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<Position, const Velocity>()
            .each([](const flecs::entity entity, Position &position, const Velocity &velocity) {
                const auto newPosition = Vector2Add(position.position, velocity.velocity);

                if (entity.has<Player>()) {
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
                } else {
                    position.position = newPosition;
                }
            });
}
