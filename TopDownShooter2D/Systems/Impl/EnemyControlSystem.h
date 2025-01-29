#pragma once
#include <flecs.h>


inline void EnemyControlSystem(const flecs::world &ecsWorld) {
    const auto playerQuery = ecsWorld.query_builder<const Position>().with<Player>().build();

    ecsWorld.system<const Position, Rotation, Velocity>()
        .with<Enemy>()
        .each([playerQuery](const Position &position, Rotation &rotation, Velocity &velocity) {
            if (const auto playerEntity = playerQuery.find([](const Position &){ return true; })) {
                const auto playerPosition = playerEntity.get<const Position>();
                velocity.velocity = Vector2Normalize(playerPosition->position - position.position) * 50.0f;
                rotation.rotation = Vector2Angle(Vector2(0, -1), velocity.velocity) * RAD2DEG;
            }
    });
}
