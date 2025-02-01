#include "Systems/Impl/EnemyControlSystem.h"

#include <raylib.h>
#include <raymath.h>
#include "Components/Impl/Enemy.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Velocity.h"


void EnemyControlSystem(const flecs::world &ecsWorld) {
    const auto playerQuery = ecsWorld.query_builder<const Position>().with<Player>().build();

    ecsWorld.system<const Position, Rotation, Velocity>(__func__)
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
