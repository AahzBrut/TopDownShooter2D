#pragma once
#include <flecs.h>

#include "Components/Impl/Collider.h"
#include "Components/Impl/Position.h"


bool IsIntersects(Position position1, Collider collider1, Position position2, Collider collider2);

void CollisionDetectionSystem(const flecs::world &ecsWorld);