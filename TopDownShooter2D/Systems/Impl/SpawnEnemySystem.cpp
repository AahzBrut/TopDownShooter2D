#include "Systems/Impl/SpawnEnemySystem.h"

#include <raylib.h>
#include <raymath.h>

#include "defs.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Spawners/EnemySpawner.h"
#include "Utils/Random.h"


void SpawnEnemySystem(const flecs::world &ecsWorld) {
    const auto playerQuery = ecsWorld.query_builder<const Position>().with<Player>().build();

    ecsWorld.system(__func__)
            .interval(ENEMY_SPAWN_INTERVAL)
            .run([&ecsWorld, playerQuery](const flecs::iter &) {
                if (const auto playerEntity = playerQuery.find([](const Position &) { return true; })) {
                    const auto playerPosition = playerEntity.get<const Position>();

                    const auto spawnAngle = RandomRange(0, PI * 2);
                    const auto spawnDirection = playerPosition->position +
                                                Vector2Rotate(Vector2{0, -1}, spawnAngle) * toFloat(WINDOW_WIDTH);
                    SpawnEnemy(ecsWorld, spawnDirection);
                }
            });
}
