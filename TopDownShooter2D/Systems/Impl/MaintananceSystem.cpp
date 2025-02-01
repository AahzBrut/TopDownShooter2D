#include "Systems/Impl/MaintananceSystem.h"

#include "defs.h"
#include "AudioManager/AudioManager.h"


void MaintananceSystem(const flecs::world &ecsWorld) {
    auto audioManager = ecsWorld.get_mut<AudioManager>();
    ecsWorld.system(__func__)
            .interval(MAINTANANCE_TIMEOUT)
            .run([audioManager](const flecs::iter) {
                audioManager->Update();
            });
}

