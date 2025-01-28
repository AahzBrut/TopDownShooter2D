#pragma once
#include <flecs.h>

constexpr int xOffsets[4] = { 0, WINDOW_WIDTH / 2,  WINDOW_WIDTH - WINDOW_WIDTH / 3, WINDOW_WIDTH - WINDOW_WIDTH / 6 };

inline void RenderWeaponsHudSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Weapon>()
            .kind(flecs::OnStore)
            .each([](const Weapon &weapon) {
                const auto hudText = std::format("{}: {:03d}", weapon.name, weapon.ammoCount);
                const auto color = weapon.isActive ? GREEN : WHITE;
                DrawText(hudText.c_str(), xOffsets[toInt(weapon.weaponType)], 5, 24, color);
            });
}
