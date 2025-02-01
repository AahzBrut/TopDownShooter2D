#include "Systems/Impl/RenderSystem.h"

#include "Components/Impl/Position.h"
#include "Components/Impl/Rotation.h"
#include "Components/Impl/Sprite.h"


void RenderSystem(const flecs::world &ecsWorld) {
    ecsWorld.system<const Position, const Rotation, const Sprite>(__func__)
            .kind(flecs::OnStore)
            .each([](const Position &position, const Rotation &rotation, const Sprite &sprite) {

                DrawTexturePro(
                    *sprite.texture,
                    sprite.GetSrcRect(),
                    sprite.GetDstRect(position.position),
                    sprite.GetCenterOrigin(),
                    rotation.rotation,
                    WHITE
                    );
            });
}
