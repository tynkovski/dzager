#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "observer.h"
#include "offset.h"
#include "weapon.h"

class OffsetFactory {
public:
    OffsetFactory(const std::vector<weapon>& weaponsv);

    std::vector<offset> createPattern(const weapon &wpn) const;
    std::vector<offset> getWeaponPattern(const std::string &str) const;

    std::vector<offset> getOverwatchPattern(const std::string &str) const;
    std::vector<offset> createSoldier();
    std::vector<offset> createBaptist();

private:
    std::unordered_map<std::string, std::vector<offset>> m_offsetTable;
    std::unordered_map<std::string, weapon> m_weaponTable;
};
