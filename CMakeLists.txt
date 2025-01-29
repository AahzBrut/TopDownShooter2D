cmake_minimum_required(VERSION 3.30)
project(TopDownShooter2D)

set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS OFF)
add_compile_definitions(FLECS_CPP_NO_AUTO_REGISTRATION)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
        flecs
        GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
        GIT_TAG v4.0.4
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib flecs)

add_executable(${CMAKE_PROJECT_NAME}
        TopDownShooter2D/main.cpp
        TopDownShooter2D/Application/Application.cpp
        TopDownShooter2D/Application/Application.h
        TopDownShooter2D/defs.h
        TopDownShooter2D/Logger.h
        TopDownShooter2D/AssetManager/AssetManager.cpp
        TopDownShooter2D/AssetManager/AssetManager.h
        TopDownShooter2D/TypeDefs.h
        TopDownShooter2D/Utils/Random.h
        TopDownShooter2D/Systems/Systems.h
        TopDownShooter2D/Components/Components.h
        TopDownShooter2D/AudioManager/AudioManager.cpp
        TopDownShooter2D/AudioManager/AudioManager.h
        TopDownShooter2D/Systems/Impl/LoadAssets.h
        TopDownShooter2D/Systems/Impl/RenderMousePointer.h
        TopDownShooter2D/Systems/Impl/MaintananceSystem.h
        TopDownShooter2D/Components/Impl/Position.h
        TopDownShooter2D/Components/Impl/Sprite.h
        TopDownShooter2D/Components/Impl/Rotation.h
        TopDownShooter2D/Spawners/PlayerSpawner.h
        TopDownShooter2D/Systems/Impl/RenderSystem.h
        TopDownShooter2D/Systems/Impl/RotatePlayerSystem.h
        TopDownShooter2D/Components/Impl/Player.h
        TopDownShooter2D/Components/Impl/Velocity.h
        TopDownShooter2D/Systems/Impl/MovementSystem.h
        TopDownShooter2D/Systems/Impl/PlayerControlSystem.h
        TopDownShooter2D/Components/Impl/Pistol.h
        TopDownShooter2D/Components/Impl/Weapon.h
        TopDownShooter2D/Systems/Impl/WeaponUpdateSystem.h
        TopDownShooter2D/Components/Impl/Shotgun.h
        TopDownShooter2D/Components/Impl/SubmachineGun.h
        TopDownShooter2D/Data/WeaponType.h
        TopDownShooter2D/Systems/Impl/PlayerShootSystem.h
        TopDownShooter2D/Systems/Impl/RenderWeaponsHudSystem.h
        TopDownShooter2D/Components/Impl/Health.h
        TopDownShooter2D/Systems/Impl/RenderPlayerHudSystem.h
        TopDownShooter2D/Components/Impl/Score.h
        TopDownShooter2D/Physics/CollisionLayersSettings.cpp
        TopDownShooter2D/Physics/CollisionLayersSettings.h
        TopDownShooter2D/Components/Impl/Collider.h
        TopDownShooter2D/Components/Impl/Damage.h
        TopDownShooter2D/Systems/Impl/SyncCollidersSystem.h
        TopDownShooter2D/Systems/Impl/RenderCollidersSystem.h
        TopDownShooter2D/Spawners/BulletSpawner.h
        TopDownShooter2D/Spawners/EnemySpawner.h
        TopDownShooter2D/Components/Impl/Enemy.h
        TopDownShooter2D/Systems/Impl/SpawnEnemySystem.h
        TopDownShooter2D/Systems/Impl/EnemyControlSystem.h
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib flecs_static)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME})

add_custom_target(COPY_ASSETS
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_CURRENT_LIST_DIR}/assets" "${CMAKE_CURRENT_BINARY_DIR}/assets"
)
add_dependencies(${CMAKE_PROJECT_NAME} COPY_ASSETS)
