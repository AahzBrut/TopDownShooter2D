#pragma once
#include "AssetManager/AssetManager.h"
#include "AudioManager/AudioManager.h"
#include "Impl/Player.h"
#include "Impl/Position.h"
#include "Impl/Rotation.h"
#include "Impl/Sprite.h"


// ReSharper disable file CppExpressionWithoutSideEffects
inline void RegisterComponents(const flecs::world &ecsWorld) {
    ecsWorld.component<AssetManager>();
    ecsWorld.component<AudioManager>();
    ecsWorld.component<Position>();
    ecsWorld.component<Rotation>();
    ecsWorld.component<Sprite>();
    ecsWorld.component<Player>();
}
