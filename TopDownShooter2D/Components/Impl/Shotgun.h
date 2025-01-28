#pragma once
#include "Weapon.h"

struct Shotgun : Weapon {
    Shotgun() : Weapon(WeaponType::SHOTGUN, "SHOTGUN", 30, 12, 5, 150, 0, false) {}
};
