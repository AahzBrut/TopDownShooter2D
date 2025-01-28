#pragma once
#include "Weapon.h"


struct Pistol : Weapon {
    Pistol() : Weapon(WeaponType::PISTOL, "PISTOL", 60, 18, 5, 150, 0, true) {}
};
