#pragma once
#include <vector>
#include "offset.h"

class OffsetFactory {
public:
    static std::vector<offset> createSoldier() {
        std::vector<offset> soldierPattern;

        for (int i = 0; i < 110; i++) {
            soldierPattern.push_back(offset(0, std::min<int>(i, 20), 1.f));
        }

        return soldierPattern;
    }

    static std::vector<offset> createBaptist() {
        std::vector<offset> baptistPattern;

        for (int i = 0; i < 10; i++) {
            baptistPattern.push_back(offset(0, 24.5f, 0.f));
        }
        for (int i = 0; i < 9; i++) {
            baptistPattern.push_back(offset(0, -6.7f, 0.f));
        }

        return baptistPattern;
    }
};

