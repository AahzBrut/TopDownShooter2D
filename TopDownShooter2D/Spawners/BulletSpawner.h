#pragma once
#include <flecs.h>
#include <raylib.h>

#include "AssetManager/AssetManager.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Damage.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Sprite.h"
#include "Components/Impl/Velocity.h"
#include "Components/Impl/Weapon.h"


inline void SpawnBullet(const flecs::world &ecsWorld, Weapon &weapon, AssetManager *assetManager,
                        const Vector2 &startPosition, float startRotation, CollisionLayer collisionLayer) {
    weapon.lastShotTime = 60.f / weapon.rateOfFire;
    ecsWorld
            .entity()
            .insert([assetManager, startPosition, startRotation, &weapon, collisionLayer](
            Position &position,
            Rotation &rotation,
            Velocity &velocity,
            Sprite &sprite,
            Damage &damage,
            Collider &collider) {
                    const auto bulletVelocity =
                            Vector2Rotate(Vector2(0, -1), startRotation * DEG2RAD) * weapon.bulletSpeed;
                    position = {startPosition};
                    rotation = {startRotation};
                    velocity = {bulletVelocity};
                    sprite = {assetManager->GetTexture("bullet")};
                    damage = {weapon.bulletDamage};
                    collider = {sprite.GetRadius(), collisionLayer};
                });
}
