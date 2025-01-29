#pragma once
#include "Weapon.h"


struct SubmachineGun : Weapon {
    SubmachineGun() : Weapon(WeaponType::SUBMACHINE_GUN, "SMG", 600, 75, 2, 500, 0, false) {}
};
