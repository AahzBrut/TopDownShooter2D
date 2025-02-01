#pragma once
#include <flecs.h>

#include "AssetManager/AssetManager.h"


inline void LoadAssets(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();
    assetManager->LoadTexture("mouse-pointer", "./assets/gfx/targetter.png");
    assetManager->LoadTexture("player", "./assets/gfx/donk.png");
    assetManager->LoadTexture("bullet", "./assets/gfx/donkBullet.png");
    assetManager->LoadTexture("enemy", "./assets/gfx/enemy01.png");
    assetManager->LoadTexture("ammo-pistol", "./assets/gfx/ammo-pistol.png");
    assetManager->LoadTexture("ammo-smg", "./assets/gfx/ammo-rifle.png");
    assetManager->LoadTexture("ammo-shotgun", "./assets/gfx/ammo-shotgun.png");
    assetManager->LoadTexture("health", "./assets/gfx/health-red.png");
}
