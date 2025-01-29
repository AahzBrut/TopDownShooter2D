#pragma once
#include <flecs.h>

#include "AssetManager/AssetManager.h"


inline void SpawnBullet(const flecs::world &ecsWorld, Weapon &weapon, AssetManager *assetManager,
                        const Vector2 &playerPosition, float playerRotation) {
    weapon.lastShotTime = 60.f / weapon.rateOfFire;
    ecsWorld
            .entity()
            .insert([assetManager, playerPosition, playerRotation, &weapon](
            Position &position,
            Rotation &rotation,
            Velocity &velocity,
            Sprite &sprite,
            Damage &damage,
            Collider &collider) {
                    const auto bulletVelocity =
                            Vector2Rotate(Vector2(0, -1), playerRotation * DEG2RAD) * weapon.bulletSpeed;
                    position = {playerPosition};
                    rotation = {playerRotation};
                    velocity = {bulletVelocity};
                    sprite = {assetManager->GetTexture("bullet")};
                    damage = {weapon.bulletDamage};
                    collider = {
                        position.position,
                        sprite.GetRadius(), CollisionLayer::PlayerBullet
                    };
                });
}

inline void PlayerShootSystem(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();

    ecsWorld.system<const Position, const Rotation, Weapon>()
            .with<Player>()
            .each([ecsWorld, assetManager](const Position &playerPosition,
                                           const Rotation &playerRotation,
                                           Weapon &weapon) {
                if (weapon.IsReady() && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                    if (weapon.weaponType == WeaponType::SHOTGUN) {
                        auto fireAngle = playerRotation.rotation - SHOTGUN_ARC / 2.f;
                        for (auto i = 0; i < 8; ++i) {
                            SpawnBullet(ecsWorld, weapon, assetManager, playerPosition.position,
                                        fireAngle);
                            fireAngle += SHOTGUN_ARC / 8.f;
                        }
                    } else {
                        SpawnBullet(ecsWorld, weapon, assetManager, playerPosition.position, playerRotation.rotation);
                    }
                    weapon.ammoCount--;
                }
            });
}
