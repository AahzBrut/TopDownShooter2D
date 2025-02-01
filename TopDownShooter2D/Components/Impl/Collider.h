#pragma once
#include "Physics/CollisionLayersSettings.h"


struct Collider {
    float radius;
    CollisionLayer collisionLayer;

    [[nodiscard]] bool IsPlayer() const { return collisionLayer == CollisionLayer::Player; }
    [[nodiscard]] bool IsEnemy() const { return collisionLayer == CollisionLayer::Enemy; }
    [[nodiscard]] bool IsBullet() const { return collisionLayer == CollisionLayer::PlayerBullet || collisionLayer == CollisionLayer::EnemyBullet; }
    [[nodiscard]] bool IsBonus() const { return collisionLayer == CollisionLayer::BonusPickup; }
};
