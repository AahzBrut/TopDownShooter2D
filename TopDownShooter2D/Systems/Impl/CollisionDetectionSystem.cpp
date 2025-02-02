#include "Systems/Impl/CollisionDetectionSystem.h"
#include <raymath.h>

#include "Logger.h"
#include "Components/Impl/Bonus.h"
#include "Components/Impl/Health.h"
#include "Components/Impl/Pistol.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Score.h"
#include "Components/Impl/Shotgun.h"
#include "Components/Impl/SubmachineGun.h"
#include "Components/Impl/Velocity.h"
#include "Spawners/BonusSpawner.h"


bool IsIntersects(const Position position1, const Collider collider1, const Position position2,
                  const Collider collider2) {
    if (!CollisionLayersSettings::IsLayersCollides(collider1.collisionLayer, collider2.collisionLayer)) return false;
    const auto [distanceX, distanceY] = position1.position - position2.position;
    const auto squaredDistance = distanceX * distanceX + distanceY * distanceY;
    return squaredDistance <= collider1.radius * collider1.radius + collider2.radius * collider2.radius;
}

void CollisionDetectionSystem(const flecs::world &ecsWorld) {
    const auto query = ecsWorld.query<const Position, const Collider>();
    const auto playerQuery = ecsWorld.query<const Player>();

    ecsWorld.system<const Position, const Collider>(__func__)
            .with<Velocity>()
            .each([&ecsWorld, query, playerQuery](const flecs::entity entity1, const Position &position1,
                                                  const Collider &collider1) {
                query.each([&ecsWorld, playerQuery, entity1, position1, collider1](
                const flecs::entity entity2, const Position &position2, const Collider &collider2) {
                        if (entity1 >= entity2) return;
                        if (IsIntersects(position1, collider1, position2, collider2)) {
                            if (collider1.IsEnemy() && collider2.IsBullet() || collider1.IsBullet() && collider2.
                                IsEnemy()) {
                                LOG("Bullet hits enemy");
                                const auto enemyPosition =
                                        collider1.IsEnemy() ? position1.position : position2.position;
                                if (const auto playerEntity = playerQuery.find([](const Player &) { return true; })) {
                                    const auto playerScore = playerEntity.get_mut<Score>();
                                    playerScore->amount += 10;
                                    SpawnBonus(ecsWorld, enemyPosition);
                                }
                            } else if (collider1.IsPlayer() && collider2.IsBonus() || collider1.IsBonus() && collider2.
                                       IsPlayer()) {
                                const auto playerEntity = collider1.IsPlayer() ? entity1 : entity2;
                                const auto bonusEntity = collider1.IsBonus() ? entity1 : entity2;
                                switch (const auto bonus = bonusEntity.get<Bonus>(); bonus->bonusType) {
                                    case BonusType::PistolAmmo:
                                        playerEntity.get_mut<Pistol>()->ammoCount += bonus->amount;
                                        break;
                                    case BonusType::ShotgunAmmo:
                                        playerEntity.get_mut<Shotgun>()->ammoCount += bonus->amount;
                                        break;
                                    case BonusType::SmgAmmo:
                                        playerEntity.get_mut<SubmachineGun>()->ammoCount += bonus->amount;
                                        break;
                                    case BonusType::Health:
                                        playerEntity.get_mut<Health>()->amount += bonus->amount;
                                        break;
                                }
                                bonusEntity.destruct();
                                return;
                            }

                            entity1.destruct();
                            entity2.destruct();
                        }
                    });
            });
}
