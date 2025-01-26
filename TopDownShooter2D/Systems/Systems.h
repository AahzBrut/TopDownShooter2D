#pragma once
#include <flecs.h>

#include "Impl/LoadAssets.h"
#include "Impl/MaintananceSystem.h"
#include "Impl/MovementSystem.h"
#include "Impl/PlayerControlSystem.h"
#include "Impl/RenderMousePointer.h"
#include "Impl/RenderSystem.h"
#include "Impl/RotatePlayerSystem.h"


inline void RegisterSystems(const flecs::world &ecsWorld) {
    LoadAssets(ecsWorld);
    PlayerControlSystem(ecsWorld);
    RotatePlayerSystem(ecsWorld);
    MovementSystem(ecsWorld);
    RenderSystem(ecsWorld);
    RenderMousePointer(ecsWorld);
    MaintananceSystem(ecsWorld);
}
