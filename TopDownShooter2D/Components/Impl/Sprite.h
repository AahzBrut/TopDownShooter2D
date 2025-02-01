#pragma once

#include <raylib.h>
#include <raymath.h>

#include "defs.h"
#include "TypeDefs.h"


struct Sprite {
    Shared<Texture2D> texture;

    [[nodiscard]] Rectangle GetSrcRect() const {
        return Rectangle{0.f, 0.f, toFloat(texture->width), toFloat(texture->height)};
    }

    [[nodiscard]] Rectangle GetDstRect(const Vector2 position) const {
        return Rectangle{position.x, position.y, toFloat(texture->width), toFloat(texture->height)};
    }

    [[nodiscard]] Vector2 GetCenterOrigin() const { return Vector2{toFloat(texture->width) * .5f, toFloat(texture->height) * .5f}; }
    [[nodiscard]] float GetRadius() const { return Vector2Length(GetCenterOrigin()); }
};
