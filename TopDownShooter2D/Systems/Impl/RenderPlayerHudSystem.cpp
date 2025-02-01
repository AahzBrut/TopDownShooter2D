#include "Systems/Impl/RenderPlayerHudSystem.h"

#include <format>
#include <raylib.h>

#include "Components/Impl/Enemy.h"
#include "Components/Impl/Health.h"
#include "Components/Impl/Player.h"
#include "Components/Impl/Score.h"


void RenderPlayerHudSystem(const flecs::world &ecsWorld) {
    const auto countEnemiesQuery = ecsWorld.query_builder().with<Enemy>().build();
    ecsWorld.system<const Health, const Score>(__func__)
            .with<Player>()
            .kind(flecs::OnStore)
            .each([countEnemiesQuery](const Health &health, const Score &score) {
                const auto enemiesCount = countEnemiesQuery.count();
                const auto healthText = std::format("HEALTH: {}", health.amount);
                const auto scoreText = std::format("SCORE: {}", score.amount);
                const auto enemiesCountText = std::format("ENEMIES: {}", enemiesCount);
                DrawText(healthText.c_str(), 5, 5, 24, WHITE);
                DrawText(scoreText.c_str(), 150, 5, 24, WHITE);
                DrawText(enemiesCountText.c_str(), 350, 5, 24, WHITE);
            });
}
