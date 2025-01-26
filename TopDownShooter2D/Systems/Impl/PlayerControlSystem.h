#pragma once
#include <flecs.h>


inline void PlayerControlSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<Velocity>()
            .with<Player>()
            .each([](const flecs::iter &it, size_t, Velocity &velocity) {
                const auto deltaTime = it.delta_time();
                Vector2 newVelocity{};
                if (IsKeyDown(KEY_W)) newVelocity.y -= 1;
                if (IsKeyDown(KEY_D)) newVelocity.x += 1;
                if (IsKeyDown(KEY_S)) newVelocity.y += 1;
                if (IsKeyDown(KEY_A)) newVelocity.x -= 1;
                velocity.velocity = Vector2Normalize(newVelocity) * (deltaTime * MAX_PLAYER_SPEED);
            });
}
