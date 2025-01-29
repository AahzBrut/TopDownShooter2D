#pragma once
#include "raylib.h"
#include "Physics/CollisionLayersSettings.h"


struct Collider {
    Vector2 center;
    float radius;
    CollisionLayer collisionLayer;
};
