#include "Application.h"
#include <raylib.h>

#include "defs.h"
#include "Components/Components.h"
#include "Systems/Systems.h"


// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::Initialize() const { // NOLINT(*-convert-member-functions-to-static)
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot 'em up");
    InitAudioDevice();

    RegisterComponents(ecsWorld);
    ecsWorld.set(AssetManager{});
    ecsWorld.set(AudioManager{});
    RegisterSystems(ecsWorld);
}

void Application::Run() {
    Initialize();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        ecsWorld.progress(GetFrameTime());

        char stringBuffer[16];
        sprintf(&stringBuffer[0], "%d", GetFPS());
        DrawText(stringBuffer, 10, 10, 32, WHITE);

        EndDrawing();
    }
    DeInitialize();
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void Application::DeInitialize() { // NOLINT(*-convert-member-functions-to-static)
    CloseAudioDevice();
    CloseWindow();
}
