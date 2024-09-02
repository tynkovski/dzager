#pragma once
#include <stdexcept>

#include "include/offset-factory.h"

const float cst = 1000.f / 30.f;

OffsetFactory::OffsetFactory(const std::vector<weapon>& weaponsv) {
    for (auto& wpn : weaponsv) {
        m_weaponTable[wpn.m_name] = wpn;
    } 

    m_offsetTable["ow.soldier"] = createSoldier();
    m_offsetTable["ow.baptist"] = createBaptist();
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
 
std::vector<offset> OffsetFactory::getWeaponPattern(const std::string& str) const {
    if (m_weaponTable.contains(str)) {
        weapon wpn = m_weaponTable.at(str);
        std::vector<offset> pattern = createPattern(wpn);
        return pattern;
    }
    throw std::invalid_argument(str);
}

std::vector<offset> OffsetFactory::getOverwatchPattern(const std::string& str) const {
    if (m_offsetTable.contains(str)) {
        return m_offsetTable.at(str);
    }
    throw std::invalid_argument(str);
}

std::vector<offset> OffsetFactory::createSoldier() {
    std::vector<offset> soldierPattern;

    for (int i = 0; i < 110; i++) {
        soldierPattern.push_back(offset(0, std::min<int>(i, 10), 1.f));
    }

    return soldierPattern;
}

std::vector<offset> OffsetFactory::createBaptist() {
    std::vector<offset> baptistPattern;

    for (int i = 0; i < 10; i++) {
        baptistPattern.push_back(offset(0, 12.25f, 0.f));
    }
    for (int i = 0; i < 9; i++) {
        baptistPattern.push_back(offset(0, -3.35f, 0.f));
    }

    return baptistPattern;
}

