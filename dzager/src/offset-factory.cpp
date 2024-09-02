#pragma once
#include <stdexcept>

#include "include/offset-factory.h"

const float cst = 1000.f / 30.f;

OffsetFactory::OffsetFactory() {

    m_weaponTable["m16"]    = new weapon("m16",    700,  30, 15.f, nullptr);
    m_weaponTable["ak47"]   = new weapon("ak47",   600,  30, 19.f, nullptr);
    m_weaponTable["ak12"]   = new weapon("ak12",   650,  30, 15.f, nullptr);
    m_weaponTable["vector"] = new weapon("vector", 1100, 25, 30.f, nullptr);
    m_weaponTable["ak308"]  = new weapon("ak308",  650,  20, 22.f, nullptr);
    m_weaponTable["ak74m"]  = new weapon("ak74m",  630,  30, 16.f, nullptr);
    m_weaponTable["g36"]    = new weapon("g36",    750,  30, 16.f, nullptr);
    m_weaponTable["val"]    = new weapon("val",    850,  20, 15.f, nullptr);
    
    m_offsetTable["ow.soldier"] = createSoldier();
    m_offsetTable["ow.baptist"] = createBaptist();
}

std::vector<offset> OffsetFactory::createPattern(weapon *wpn) const {
    std::vector<offset> pattern;

    if (wpn == nullptr) return pattern;

    float rps = wpn->rpm / 60.f;

    int burstTicks = (int) ((float)wpn->magSize / rps * cst);
    float aimMultiplier = wpn->scope == nullptr
        ? 1.f
        : wpn->scope->aimMultiplier;

    for (int i = 0; i < burstTicks; i++) {
        pattern.push_back(offset(0, wpn->recoil, aimMultiplier));
    }

    float releaseTicks = 20;
    for (int i = 0; i < releaseTicks; i++) {
        pattern.push_back(offset(0, 0, 0.f));
    }

    return pattern;
}
 
std::vector<offset> OffsetFactory::getWeaponPattern(const std::string& str) const {
    if (m_weaponTable.contains(str)) {
        weapon* wpn = m_weaponTable.at(str);
        std::vector<offset> pattern = createPattern(wpn);
        return pattern;
    }
    throw std::invalid_argument(str);
}

std::vector<offset> OffsetFactory::getPattern(const std::string& str) const {
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

// deprecated
std::vector<offset> OffsetFactory::createVector() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 45; i++) {
        vectorPattern.push_back(offset(0, 30.f, 1.4f));
    }
    for (int i = 0; i < 25; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk308() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 60; i++) {
        vectorPattern.push_back(offset(0, 22.f, 0.8f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk74m() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 95; i++) {
        vectorPattern.push_back(offset(0, 16.f, 2.04f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createVal() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 60; i++) {
        vectorPattern.push_back(offset(0, 15.f, 1.0f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk12() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 95; i++) {
        vectorPattern.push_back(offset(0, 15.f, 1.f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}


std::vector<offset> OffsetFactory::createG36() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 80; i++) {
        vectorPattern.push_back(offset(0, 16.f, 0.85f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}
