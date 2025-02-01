#include "Spawners/BonusSpawner.h"

#include "AssetManager/AssetManager.h"
#include "Components/Impl/Bonus.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Sprite.h"
#include "Data/BonusType.h"
#include "Utils/Random.h"


constexpr std::string bonusSprites[] = {
    "ammo-pistol",
    "ammo-shotgun",
    "ammo-smg",
    "health"
};

constexpr int bonusAmounts[] = {
    16,
    8,
    50,
    5
};

void SpawnBonus(const flecs::world &ecsWorld, const Vector2 &spawnPosition) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();

    const auto bonusType = static_cast<BonusType>(RandomIntRange(0, 3));

    ecsWorld
            .entity()
            .insert([assetManager, bonusType, spawnPosition](
            Position &position,
            Rotation &rotation,
            Sprite &sprite,
            Collider &collider,
            Bonus &bonus) {
                    position = {spawnPosition};
                    rotation = {};
                    sprite = {assetManager->GetTexture(bonusSprites[toInt(bonusType)])};
                    collider = {sprite.GetRadius(), CollisionLayer::BonusPickup};
                    bonus = {bonusType, bonusAmounts[toInt(bonusType)]};
                });
}
