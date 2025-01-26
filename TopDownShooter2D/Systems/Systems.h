#pragma once
#include <flecs.h>

#include "Impl/LoadAssets.h"
#include "Impl/MaintananceSystem.h"
#include "Impl/RenderMousePointer.h"
#include "Impl/RenderSystem.h"
#include "Impl/RotatePlayerSystem.h"


inline void RegisterSystems(const flecs::world &ecsWorld) {
    LoadAssets(ecsWorld);
    MaintananceSystem(ecsWorld);
    RenderSystem(ecsWorld);
    RenderMousePointer(ecsWorld);
    RotatePlayerSystem(ecsWorld);
}
