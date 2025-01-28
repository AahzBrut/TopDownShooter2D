#pragma once
#include "AssetManager/AssetManager.h"
#include "AudioManager/AudioManager.h"
#include "Impl/Health.h"
#include "Impl/Pistol.h"
#include "Impl/Player.h"
#include "Impl/Position.h"
#include "Impl/Rotation.h"
#include "Impl/Score.h"
#include "Impl/Shotgun.h"
#include "Impl/Sprite.h"
#include "Impl/SubmachineGun.h"
#include "Impl/Velocity.h"
#include "Impl/Weapon.h"


// ReSharper disable file CppExpressionWithoutSideEffects
inline void RegisterComponents(const flecs::world &ecsWorld) {
    ecsWorld.component<AssetManager>();
    ecsWorld.component<AudioManager>();
    ecsWorld.component<Position>();
    ecsWorld.component<Rotation>();
    ecsWorld.component<Sprite>();
    ecsWorld.component<Player>();
    ecsWorld.component<Velocity>();
    ecsWorld.component<Weapon>();
    ecsWorld.component<Pistol>().is_a<Weapon>();
    ecsWorld.component<Shotgun>().is_a<Weapon>();
    ecsWorld.component<SubmachineGun>().is_a<Weapon>();
    ecsWorld.component<Health>();
    ecsWorld.component<Score>();
}
