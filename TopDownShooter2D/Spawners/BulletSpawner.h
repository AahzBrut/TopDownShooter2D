#pragma once
#include <flecs.h>
#include <raylib.h>

#include "AssetManager/AssetManager.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Weapon.h"


void SpawnBullet(const flecs::world &ecsWorld, Weapon &weapon, AssetManager *assetManager,
                 const Vector2 &startPosition, float startRotation, CollisionLayer collisionLayer);
