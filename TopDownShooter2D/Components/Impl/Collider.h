#pragma once
#include "raylib.h"
#include "Physics/CollisionLayersSettings.h"


struct Collider {
    float radius;
    CollisionLayer collisionLayer;
};
