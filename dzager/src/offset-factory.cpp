#pragma once
#include <stdexcept>

#include "include/offset-factory.h"

const float cst = 1000.f / 30.f;

OffsetFactory::OffsetFactory() {}

OffsetFactory::OffsetFactory(const std::vector<weapon>& weaponsv) {
    for (auto& wpn : weaponsv) {
        m_weaponTable[wpn.m_name] = wpn;
    }
}

std::vector<offset> OffsetFactory::createPattern(const weapon &wpn) const {
    std::vector<offset> pattern;

    float rps = wpn.m_rpm / 60.f;

    int burstTicks = (int) ((float)wpn.m_magSize / rps * cst);

    for (int i = 0; i < burstTicks; i++) {
        pattern.push_back(offset(0, wpn.m_recoil, wpn.m_scope.aimMultiplier));
    }

    float releaseTicks = 20;
    for (int i = 0; i < releaseTicks; i++) {
        pattern.push_back(offset(0, 0, 0.f));
    }

    return pattern;
}
 
weapon OffsetFactory::getWeapon(const std::string& str) const {
    if (m_weaponTable.contains(str)) {
        return m_weaponTable.at(str);
    }
    throw std::invalid_argument(str);
}

std::vector<offset> OffsetFactory::getWeaponPattern(const std::string& str) const {
    weapon wpn = getWeapon(str);
    std::vector<offset> pattern = createPattern(wpn);
    return pattern;
}
