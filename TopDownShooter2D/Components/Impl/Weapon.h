#pragma once
#include "Data/WeaponType.h"


struct Weapon {
    using String = std::string;

    WeaponType weaponType;
    String name;
    float rateOfFire;
    int ammoCount;
    float bulletDamage;
    float bulletSpeed;
    float lastShotTime;
    bool isActive;

    Weapon(
        const WeaponType weaponType,
        String name,
        const float rateOfFire,
        const int ammoCount,
        const float bulletDamage,
        const float bulletSpeed,
        const float lastShotTime,
        const bool isActive)
        : weaponType{weaponType},
          name{std::move(name)},
          rateOfFire{rateOfFire},
          ammoCount{ammoCount},
          bulletDamage{bulletDamage},
          bulletSpeed{bulletSpeed},
          lastShotTime{lastShotTime},
          isActive{isActive} {}

    [[nodiscard]] bool IsReady() const { return lastShotTime <= 0.f && isActive && ammoCount > 0; }
};
