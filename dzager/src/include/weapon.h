#pragma once
#include <string>
#include <vector>

#include "scope.h"
#include "json/json.h"  

struct weapon {
    weapon(std::string name, int rpm, int magSize, float recoil) {
        this->m_name    = name;
        this->m_rpm     = rpm;
        this->m_magSize = magSize;
        this->m_recoil  = recoil;
        this->m_scope   = scope();
    }

    weapon() {
        this->m_name    = "none";
        this->m_rpm     = 0;
        this->m_magSize = 0;
        this->m_recoil  = 0.f;
        this->m_scope   = scope();
    }

    int         m_rpm;
    int         m_magSize;
    float       m_recoil;
    scope       m_scope;
    std::string m_name;
};

static inline std::vector<weapon> read_weapons_json(std::string json) {
    std::vector<weapon> weaponsv;

    auto j = nlohmann::json::parse(json);
    auto weapons = j["weapons"];

    for (auto& w : weapons) {
        std::string name = w["name"];
        int rpm          = w["rpm"];
        int magSize      = w["magSize"];
        float recoil     = w["recoil"];
        weaponsv.push_back(weapon(name, rpm, magSize, recoil));
    }
    return weaponsv;
}