#include "Systems/Impl/PlayerControlSystem.h"

#include <raylib.h>
#include <raymath.h>

#include "defs.h"
#include "Logger.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Velocity.h"
#include "Components/Impl/Weapon.h"


void PlayerControlSystem(const flecs::world &ecsWorld) {
    auto weaponsQuery = ecsWorld.query_builder<Weapon>().with<Player>().build();

    ecsWorld.system<Velocity>(__func__)
            .with<Player>()
            .each([weaponsQuery](Velocity &velocity) {
                Vector2 newVelocity{};
                if (IsKeyDown(KEY_W)) newVelocity.y -= 1;
                if (IsKeyDown(KEY_D)) newVelocity.x += 1;
                if (IsKeyDown(KEY_S)) newVelocity.y += 1;
                if (IsKeyDown(KEY_A)) newVelocity.x -= 1;

                if (auto selectedWeapon = IsKeyPressed(KEY_ONE)
                                              ? 1
                                              : IsKeyPressed(KEY_TWO)
                                                    ? 2
                                                    : IsKeyPressed(KEY_THREE)
                                                          ? 3
                                                          : 0; selectedWeapon) {
                    weaponsQuery.each([selectedWeapon](Weapon &weapon) {
                        weapon.isActive = static_cast<int>(weapon.weaponType) == selectedWeapon;
                        if (weapon.isActive) { LOG("Weapon selected: {}", weapon.name); }
                    });
                }
                velocity.velocity = Vector2Normalize(newVelocity) * MAX_PLAYER_SPEED;
            });
}
