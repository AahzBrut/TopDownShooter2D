#pragma once
#include <flecs.h>
#include <raymath.h>

#include "Components/Impl/Collider.h"
#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Shotgun.h"
#include "Components/Impl/Sprite.h"


inline void SpawnPlayer(const flecs::world &ecsWorld) {
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
                shotgun = {};
                smg = {};
                health = {5, 5};
                score = {};
                collider = { position.position, sprite.GetRadius(), CollisionLayer::Player};
            }).add<Player>();
}
