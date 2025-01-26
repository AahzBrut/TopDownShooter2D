#pragma once
#include <flecs.h>

#include "AssetManager/AssetManager.h"


inline void RenderMousePointer(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();
    const auto mousePointer = assetManager->GetTexture("mouse-pointer");
    const auto mousePointerWidth = mousePointer->width / 2;
    const auto mousePointerHeight = mousePointer->height / 2;
    ecsWorld.system()
            .kind(flecs::OnStore)
            .run([mousePointer, mousePointerWidth, mousePointerHeight](const flecs::iter &) {
                const auto [mouseX, mouseY] = GetMousePosition();
                DrawTexture(*mousePointer,
                            toInt(mouseX) - mousePointerWidth,
                            toInt(mouseY) - mousePointerHeight,
                            WHITE);
            });
}
