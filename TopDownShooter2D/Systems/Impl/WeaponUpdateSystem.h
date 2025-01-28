#pragma once
#include <flecs.h>

inline void WeaponUpdateSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<Weapon>()
        .each([](const flecs::iter &it, size_t, Weapon &weapon) {
            const auto deltaTime = it.delta_time();
            weapon.lastShotTime = weapon.lastShotTime > 0.f ? weapon.lastShotTime - deltaTime : 0.f;
    });
}
