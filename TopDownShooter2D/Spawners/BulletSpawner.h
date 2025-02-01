#pragma once
#include <flecs.h>
#include <raylib.h>


enum class CollisionLayer;
struct Weapon;
class AssetManager;

void SpawnBullet(const flecs::world &ecsWorld, Weapon &weapon, AssetManager *assetManager,
                 const Vector2 &startPosition, float startRotation, CollisionLayer collisionLayer);
