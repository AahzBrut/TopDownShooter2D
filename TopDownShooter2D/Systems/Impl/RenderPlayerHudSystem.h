#pragma once
#include <flecs.h>


inline void RenderPlayerHudSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Health, const Score>()
            .with<Player>()
            .kind(flecs::OnStore)
            .each([](const Health &health, const Score &score) {
                const auto healthText = std::format("HEALTH: {}", health.amount);
                const auto scoreText = std::format("SCORE: {}", score.amount);
                DrawText(healthText.c_str(), 5, 5, 24, WHITE);
                DrawText(scoreText.c_str(), 200, 5, 24, WHITE);
            });
}
