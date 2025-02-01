#include "Systems/Impl/PlayerShootSystem.h"

#include "defs.h"
#include "AssetManager/AssetManager.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Weapon.h"
#include "Spawners/BulletSpawner.h"


void PlayerShootSystem(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();

    ecsWorld.system<const Position, const Rotation, Weapon>(__func__)
            .with<Player>()
            .each([ecsWorld, assetManager](const Position &playerPosition,
                                           const Rotation &playerRotation,
                                           Weapon &weapon) {
                if (weapon.IsReady() && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    if (weapon.weaponType == WeaponType::SHOTGUN) {
                        auto fireAngle = playerRotation.rotation - SHOTGUN_ARC / 2.f;
                        for (auto i = 0; i < 8; ++i) {
                            SpawnBullet(ecsWorld, weapon, assetManager, playerPosition.position,
                                        fireAngle, CollisionLayer::PlayerBullet);
                            fireAngle += SHOTGUN_ARC / 8.f;
                        }
                    } else {
                        SpawnBullet(ecsWorld, weapon, assetManager, playerPosition.position, playerRotation.rotation, CollisionLayer::PlayerBullet);
                    }
                    weapon.ammoCount--;
                }
            });
}
