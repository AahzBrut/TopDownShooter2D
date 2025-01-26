#pragma once
#include <flecs.h>

#include "Impl/LoadAssets.h"
#include "Impl/MaintananceSystem.h"
#include "Impl/RenderMousePointer.h"


inline void RegisterSystems(const flecs::world &ecsWorld) {
    LoadAssets(ecsWorld);
    MaintananceSystem(ecsWorld);
    RenderMousePointer(ecsWorld);
}
