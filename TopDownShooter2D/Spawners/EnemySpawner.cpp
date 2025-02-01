#include "Spawners/EnemySpawner.h"

#include "AssetManager/AssetManager.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Enemy.h"
#include "Components/Impl/Health.h"
#include "Components/Impl/Pistol.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Score.h"
#include "Components/Impl/Shotgun.h"
#include "Components/Impl/Sprite.h"
#include "Components/Impl/SubmachineGun.h"
#include "Components/Impl/Velocity.h"


void SpawnEnemy(const flecs::world &ecsWorld, Vector2 spawnPosition) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();

    // ReSharper disable once CppExpressionWithoutSideEffects
    ecsWorld
            .entity()
            .insert([assetManager, spawnPosition](
                Position &position,
                Rotation &rotation,
                Sprite &sprite,
                Velocity &velocity,
                Pistol &pistol,
                Shotgun &shotgun,
                SubmachineGun &smg,
                Health &health,
                Score &score,
                Collider &collider
                ) {
                position = {spawnPosition};
                rotation = {};
                sprite = {assetManager->GetTexture("enemy")};
                velocity = {};
                pistol = {};
                shotgun = {};
                smg = {};
                health = {5, 5};
                score = {};
                collider = { sprite.GetRadius() * 0.6f, CollisionLayer::Enemy};
            }).add<Enemy>();
}
