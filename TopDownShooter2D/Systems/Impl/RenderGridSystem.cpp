#include "Systems/Impl/RenderGridSystem.h"

#include "defs.h"
#include "AssetManager/AssetManager.h"


void RenderGridSystem(const flecs::world &ecsWorld) {
    const auto assetManager = ecsWorld.get_mut<AssetManager>();
    const auto camera = ecsWorld.get<Camera2D>();

    ecsWorld.system(__func__)
            .kind(flecs::OnStore)
            .run([assetManager, camera](flecs::iter &) {
                BeginMode2D(*camera);
                const auto gridTexture = assetManager->GetTexture("grid");
                constexpr auto textureRect = Rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
                DrawTexturePro(*gridTexture, textureRect, textureRect, {0,0}, 0, WHITE);
            });
}
