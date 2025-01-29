#pragma once
#include "Weapon.h"

struct Shotgun : Weapon {
    Shotgun() : Weapon(WeaponType::SHOTGUN, "SHOTGUN", 30, 12, 1, 350, 0, false) {}
};
