#include "Systems/Impl/RenderMousePointer.h"

#include "defs.h"
#include "AssetManager/AssetManager.h"

void RenderMousePointer(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();
    const auto mousePointer = assetManager->GetTexture("mouse-pointer");
    const auto mousePointerWidth = mousePointer->width / 2;
    const auto mousePointerHeight = mousePointer->height / 2;
    ecsWorld.system(__func__)
            .kind(flecs::OnStore)
            .run([mousePointer, mousePointerWidth, mousePointerHeight](const flecs::iter &) {
                const auto [mouseX, mouseY] = GetMousePosition();
                DrawTexture(*mousePointer,
                            toInt(mouseX) - mousePointerWidth,
                            toInt(mouseY) - mousePointerHeight,
                            WHITE);
            });
}
