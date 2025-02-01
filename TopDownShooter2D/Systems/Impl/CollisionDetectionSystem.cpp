#include "Systems/Impl/CollisionDetectionSystem.h"
#include <raymath.h>

#include "Logger.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Score.h"
#include "Spawners/BonusSpawner.h"


bool IsIntersects(const Position position1, const Collider collider1, const Position position2, const Collider collider2) {
    if (!CollisionLayersSettings::IsLayersCollides(collider1.collisionLayer, collider2.collisionLayer)) return false;
    const auto [distanceX, distanceY] = position1.position - position2.position;
    const auto squaredDistance = distanceX * distanceX + distanceY * distanceY;
    return squaredDistance <= collider1.radius * collider1.radius + collider2.radius * collider2.radius;
}

void CollisionDetectionSystem(const flecs::world &ecsWorld) {
    const auto query = ecsWorld.query<const Position, const Collider>();
    const auto playerQuery = ecsWorld.query<const Player>();

    ecsWorld.system<const Position, const Collider>(__func__)
            .each([&ecsWorld, query, playerQuery](const flecs::entity entity1, const Position &position1, const Collider &collider1) {
                query.each([&ecsWorld, playerQuery, entity1, position1, collider1](
                const flecs::entity entity2, const Position &position2, const Collider &collider2) {
                        if (entity1 >= entity2) return;
                        if (IsIntersects(position1, collider1, position2, collider2)) {
                            if (collider1.IsEnemy() && collider2.IsBullet() || collider1.IsBullet() && collider2.IsEnemy() ) {
                                LOG("Bullet hits enemy");
                                const auto enemyPosition = collider1.IsEnemy() ? position1.position : position2.position;
                                if (const auto playerEntity = playerQuery.find([](const Player &) { return true; })) {
                                    const auto playerScore = playerEntity.get_mut<Score>();
                                    playerScore->amount += 10;
                                    SpawnBonus(ecsWorld, enemyPosition);
                                }
                            }

                            entity1.destruct();
                            entity2.destruct();
                        }
                    });
            });
}

