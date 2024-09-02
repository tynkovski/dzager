#pragma once

#include <string>

struct scope {
    scope(std::string name, float aimMultiplier) {
        this->name          = name;
        this->aimMultiplier = aimMultiplier;
    }

    scope() {
        this->name = "none";
        this->aimMultiplier = 1.f;
    }

    float       aimMultiplier;
    std::string name;
};