#pragma once
#include <flecs.h>

class Application {
    flecs::world ecsWorld;

public:
    Application(const int argc, char ** argv): ecsWorld{argc, argv} {}

    void Run();

private:
    void Initialize();
    void DeInitialize();
};
