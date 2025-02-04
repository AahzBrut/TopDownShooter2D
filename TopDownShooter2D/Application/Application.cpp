#include "Application.h"
#include <raylib.h>

#include "defs.h"
#include "AssetManager/AssetManager.h"
#include "AudioManager/AudioManager.h"
#include "Components/Components.h"
#include "Spawners/PlayerSpawner.h"
#include "Systems/Systems.h"


// ReSharper disable once CppMemberFunctionMayBeConst
void Application::Initialize() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot 'em up");
    InitAudioDevice();

    // SetTargetFPS(60);
    // ecsWorld.import<flecs::units>();
    // ecsWorld.import<flecs::stats>();
    // ecsWorld.set<flecs::Rest>({});

    RegisterComponents(ecsWorld);
    ecsWorld.set(AssetManager{});
    ecsWorld.set(AudioManager{});
    ecsWorld.set(Camera2D{{},{}, 0, 1});
    RegisterSystems(ecsWorld);

    SpawnPlayer(ecsWorld);
}

void Application::Run() {
    Initialize();
    DisableCursor();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        ecsWorld.progress(GetFrameTime());

        const auto fpsString = std::format("{}", GetFPS());
        DrawText(fpsString.c_str(), 10, 30, 32, WHITE);

        EndDrawing();
    }
    DeInitialize();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::DeInitialize() { // NOLINT(*-convert-member-functions-to-static)
    CloseAudioDevice();
    CloseWindow();
}
