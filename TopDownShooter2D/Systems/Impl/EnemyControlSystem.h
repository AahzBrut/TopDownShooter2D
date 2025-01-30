#pragma once
#include <flecs.h>
#include <raymath.h>


inline void EnemyControlSystem(const flecs::world &ecsWorld) {
    const auto playerQuery = ecsWorld.query_builder<const Position>().with<Player>().build();

    ecsWorld.system<const Position, Rotation, Velocity>()
            .with<Enemy>()
            .run([playerQuery](flecs::iter &it) {
                playerQuery.each([&it](const Position &playerPosition) {
                    while (it.next()) {
                        const auto enemyPosition = it.field<const Position>(0);
                        auto enemyRotation = it.field<Rotation>(1);
                        auto enemyVelocity = it.field<Velocity>(2);
                        for (const auto enemyId: it) {
                            enemyVelocity[enemyId].velocity = Vector2Normalize(
                                                                  playerPosition.position - enemyPosition[enemyId].
                                                                  position) * 50.0f;
                            enemyRotation[enemyId].rotation = Vector2Angle(Vector2(0, -1),
                                                                           enemyVelocity[enemyId].velocity) * RAD2DEG;
                        }
                    }
                });
            });
}
