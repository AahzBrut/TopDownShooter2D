#pragma once
#include <flecs.h>

#include "Impl/BulletDestructionSystem.h"
#include "Impl/CollisionDetectionSystem.h"
#include "Impl/EnemyControlSystem.h"
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
#include "Impl/SpawnEnemySystem.h"
#include "Impl/WeaponUpdateSystem.h"


inline void RegisterSystems(const flecs::world &ecsWorld) {
    LoadAssets(ecsWorld);
    WeaponUpdateSystem(ecsWorld);
    PlayerControlSystem(ecsWorld);
    PlayerShootSystem(ecsWorld);
    RotatePlayerSystem(ecsWorld);
    MovementSystem(ecsWorld);
    CollisionDetectionSystem(ecsWorld);
    BulletDestructionSystem(ecsWorld);
    RenderSystem(ecsWorld);
    RenderMousePointer(ecsWorld);
    RenderWeaponsHudSystem(ecsWorld);
    RenderPlayerHudSystem(ecsWorld);
    RenderCollidersSystem(ecsWorld);
    MaintananceSystem(ecsWorld);
    SpawnEnemySystem(ecsWorld);
    EnemyControlSystem(ecsWorld);
}
