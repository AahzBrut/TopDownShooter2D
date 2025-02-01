#include "Systems/Impl/BulletDestructionSystem.h"

#include "Logger.h"
#include "Components/Impl/Collider.h"
#include "Components/Impl/Position.h"


void BulletDestructionSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Position, const Collider>(__func__)
            .each([](const flecs::entity entity, const Position &position, const Collider &collider) {
                if (collider.IsBullet() && position.IsOutOfBounds()) {
                    entity.destruct();
                }
            });
}
