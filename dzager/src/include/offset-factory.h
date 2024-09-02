#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "observer.h"
#include "offset.h"
#include "include/weapon.h"

class OffsetFactory {
public:
    OffsetFactory();

    std::vector<offset> createPattern(weapon* wpn) const;

    std::vector<offset> getWeaponPattern(const std::string &str) const;
    std::vector<offset> getPattern(const std::string &str) const;

    std::vector<offset> createSoldier();
    std::vector<offset> createBaptist();

    // deprecated
    std::vector<offset> createAk12();
    std::vector<offset> createVector();
    std::vector<offset> createAk308();
    std::vector<offset> createAk74m();
    std::vector<offset> createVal();
    std::vector<offset> createG36();

private:
    std::unordered_map<std::string, std::vector<offset>> m_offsetTable;
    std::unordered_map<std::string, weapon*> m_weaponTable;
};
