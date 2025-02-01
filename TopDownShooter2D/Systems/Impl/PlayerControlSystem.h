#pragma once
#include <flecs.h>


inline void PlayerControlSystem(const flecs::world &ecsWorld) {
    auto weaponsQuery = ecsWorld.query<Weapon>();

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
