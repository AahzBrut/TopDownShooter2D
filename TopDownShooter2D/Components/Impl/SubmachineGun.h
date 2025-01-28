#pragma once
#include "Weapon.h"


struct SubmachineGun : Weapon {
    SubmachineGun() : Weapon(WeaponType::SUBMACHINE_GUN, "SMG", 600, 75, 5, 150, 0, false) {}
};
