#pragma once

#include <string>

struct scope {
    scope(std::string name, float aimMultiplier) {
        this->name          = name;
        this->aimMultiplier = aimMultiplier;
    }

    float       aimMultiplier;
    std::string name;
};