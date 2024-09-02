#pragma once
#include <string>

#include "scope.h"

struct weapon {
    weapon(std::string name, int rpm, int magSize, float recoil, scope* scope = nullptr) {
        this->name    = name;
        this->rpm     = rpm;
        this->magSize = magSize;
        this->recoil  = recoil;
        this->scope   = scope;
    }

    int         rpm;
    int         magSize;
    float       recoil;
    scope*      scope;
    std::string name;
};