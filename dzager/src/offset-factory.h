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

    static std::vector<offset> createVector() {
        std::vector<offset> vectorPattern;

        for (int i = 0; i < 45; i++) {
            vectorPattern.push_back(offset(0, 60.f, 1.4f));
        }
        for (int i = 0; i < 25; i++) {
            vectorPattern.push_back(offset(0, 0, 0.0f));
        }

        return vectorPattern;
    }

    static std::vector<offset> createAk308() {
        std::vector<offset> vectorPattern;

        for (int i = 0; i < 60; i++) {
            vectorPattern.push_back(offset(0, 44.f, 1.3f));
        }
        for (int i = 0; i < 20; i++) {
            vectorPattern.push_back(offset(0, 0, 0.0f));
        }

        return vectorPattern;
    }

    static std::vector<offset> createAk74m() {
        std::vector<offset> vectorPattern;

        for (int i = 0; i < 95; i++) {
            vectorPattern.push_back(offset(0, 32.f, 2.04f));
        }
        for (int i = 0; i < 20; i++) {
            vectorPattern.push_back(offset(0, 0, 0.0f));
        }

        return vectorPattern;
    }

    static std::vector<offset> createAk12() {
        std::vector<offset> vectorPattern;

        for (int i = 0; i < 95; i++) {
            vectorPattern.push_back(offset(0, 30.f, 1.f));
        }
        for (int i = 0; i < 20; i++) {
            vectorPattern.push_back(offset(0, 0, 0.0f));
        }

        return vectorPattern;
    }

    static std::vector<offset> createG36() {
        std::vector<offset> vectorPattern;

        for (int i = 0; i < 80; i++) {
            vectorPattern.push_back(offset(0, 33.f, 0.85f));
        }
        for (int i = 0; i < 20; i++) {
            vectorPattern.push_back(offset(0, 0, 0.0f));
        }

        return vectorPattern;
    }
};

