#include "Spawners/PlayerSpawner.h"

#include "AssetManager/AssetManager.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Health.h"
#include "Components/Impl/Pistol.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Score.h"
#include "Components/Impl/Shotgun.h"
#include "Components/Impl/Sprite.h"
#include "Components/Impl/SubmachineGun.h"
#include "Components/Impl/Velocity.h"


void SpawnPlayer(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();

    // ReSharper disable once CppExpressionWithoutSideEffects
    ecsWorld
            .entity()
            .insert([assetManager](
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
                position = {toFloat(WINDOW_WIDTH) * 0.5f, toFloat(WINDOW_HEIGHT) * 0.5f};
                rotation = {};
                sprite = {assetManager->GetTexture("player")};
                velocity = {};
                pistol = {};
                shotgun = {};
                smg = {};
                health = {5, 5};
                score = {};
                collider = { sprite.GetRadius() * .8f, CollisionLayer::Player};
            }).add<Player>();
}
