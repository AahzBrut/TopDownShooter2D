#pragma once
#include <flecs.h>

#include "Impl/LoadAssets.h"
#include "Impl/MaintananceSystem.h"
#include "Impl/MovementSystem.h"
#include "Impl/PlayerControlSystem.h"
#include "Impl/PlayerShootSystem.h"
#include "Impl/RenderCollidersSystem.h"
#include "Impl/RenderMousePointer.h"
#include "Impl/RenderPlayerHudSystem.h"
#include "Impl/RenderSystem.h"
#include "Impl/RenderWeaponsHudSystem.h"
#include "Impl/RotatePlayerSystem.h"
#include "Impl/SyncCollidersSystem.h"
#include "Impl/WeaponUpdateSystem.h"


inline void RegisterSystems(const flecs::world &ecsWorld) {
    LoadAssets(ecsWorld);
    WeaponUpdateSystem(ecsWorld);
    PlayerControlSystem(ecsWorld);
    PlayerShootSystem(ecsWorld);
    RotatePlayerSystem(ecsWorld);
    MovementSystem(ecsWorld);
    SyncCollidersSystem(ecsWorld);
    RenderSystem(ecsWorld);
    RenderMousePointer(ecsWorld);
    RenderWeaponsHudSystem(ecsWorld);
    RenderPlayerHudSystem(ecsWorld);
    //RenderCollidersSystem(ecsWorld);
    MaintananceSystem(ecsWorld);
}
