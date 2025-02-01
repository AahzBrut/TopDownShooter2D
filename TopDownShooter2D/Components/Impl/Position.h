#pragma once
#include <raylib.h>

#include "defs.h"


struct Position {
    Vector2 position;

    [[nodiscard]] bool IsOutOfBounds() const {
        return position.x < -WINDOW_WIDTH || position.x > WINDOW_WIDTH * 2 ||
               position.y < -WINDOW_HEIGHT || position.y > WINDOW_HEIGHT * 2;
    }
};
