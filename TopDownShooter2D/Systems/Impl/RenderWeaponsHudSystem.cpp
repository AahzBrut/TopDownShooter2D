#include "Systems/Impl/RenderWeaponsHudSystem.h"

#include <format>

#include "defs.h"
#include "raylib.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Weapon.h"


constexpr int xOffsets[4] = {0, WINDOW_WIDTH / 2, WINDOW_WIDTH - WINDOW_WIDTH / 3, WINDOW_WIDTH - WINDOW_WIDTH / 6};

void RenderWeaponsHudSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Weapon>(__func__)
            .with<Player>()
            .kind(flecs::OnStore)
            .each([](const Weapon &weapon) {
                const auto hudText = std::format("{}: {:03d}", weapon.name, weapon.ammoCount);
                const auto color = weapon.ammoCount > 0
                                       ? weapon.isActive
                                             ? weapon.lastShotTime > 0
                                                   ? YELLOW
                                                   : GREEN
                                             : WHITE
                                       : RED;
                DrawText(hudText.c_str(), xOffsets[toInt(weapon.weaponType)], 5, 24, color);
            });
}
