#pragma once
#include <flecs.h>

#include "AssetManager/AssetManager.h"


inline void LoadAssets(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();
    assetManager->LoadTexture("mouse-pointer", "./assets/gfx/targetter.png");
}
