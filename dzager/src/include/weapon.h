#pragma once
#include <string>
#include <vector>

#include "scope.h"
#include "json/json.h"  

struct weapon {
    weapon(std::string name, int rpm, int magSize, float recoil, scope _scope) {
        this->m_name    = name;
        this->m_rpm     = rpm;
        this->m_magSize = magSize;
        this->m_recoil  = recoil;
        this->m_scope   = _scope;
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
    std::vector<weapon> weapons;
    std::unordered_map<std::string, scope> scopes;

    auto jRoot = nlohmann::json::parse(json);
    auto jWeapons = jRoot["weapons"];
    auto jScopes = jRoot["scopes"];

    for (auto& s : jScopes) {
        std::string name    = s["name"];
        float aimMultiplier = s["aimMultiplier"];

        scopes[name] = scope(name, aimMultiplier);
    }

    for (auto& w : jWeapons) {
        std::string name = w["name"];
        int rpm          = w["rpm"];
        int magSize      = w["magSize"];
        float recoil     = w["recoil"];

        std::string scopeName = w["scope"];

        scope _scope = scopes.contains(scopeName) ? scopes[scopeName] : scope();

        weapons.push_back(weapon(name, rpm, magSize, recoil, _scope));
    }

    return weapons;
}