#pragma once
#include "offset-factory.h"

OffsetFactory::OffsetFactory() {
    m_offsetTable["ak12"]   = createAk12();
    m_offsetTable["vector"] = createVector();
    m_offsetTable["ak308"]  = createAk308();
    m_offsetTable["ak74m"]  = createAk74m();
    m_offsetTable["g36"]    = createG36();
    m_offsetTable["val"]    = createVal();
}

std::vector<offset> OffsetFactory::getPattern(const std::string& str) const {
    if (m_offsetTable.contains(str)) {
        return m_offsetTable.at(str);
    } else {
        throw std::invalid_argument(str);
    }
}

std::vector<offset> OffsetFactory::createSoldier() {
    std::vector<offset> soldierPattern;

    for (int i = 0; i < 110; i++) {
        soldierPattern.push_back(offset(0, std::min<int>(i, 20), 1.f));
    }

    return soldierPattern;
}

std::vector<offset> OffsetFactory::createBaptist() {
    std::vector<offset> baptistPattern;

    for (int i = 0; i < 10; i++) {
        baptistPattern.push_back(offset(0, 24.5f, 0.f));
    }
    for (int i = 0; i < 9; i++) {
        baptistPattern.push_back(offset(0, -6.7f, 0.f));
    }

    return baptistPattern;
}

std::vector<offset> OffsetFactory::createVector() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 45; i++) {
        vectorPattern.push_back(offset(0, 60.f, 1.4f));
    }
    for (int i = 0; i < 25; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk308() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 60; i++) {
        vectorPattern.push_back(offset(0, 44.f, 1.3f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk74m() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 95; i++) {
        vectorPattern.push_back(offset(0, 32.f, 2.04f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createVal() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 60; i++) {
        vectorPattern.push_back(offset(0, 30.f, 1.5f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}

std::vector<offset> OffsetFactory::createAk12() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 95; i++) {
        vectorPattern.push_back(offset(0, 30.f, 1.f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}


std::vector<offset> OffsetFactory::createG36() {
    std::vector<offset> vectorPattern;

    for (int i = 0; i < 80; i++) {
        vectorPattern.push_back(offset(0, 33.f, 0.85f));
    }
    for (int i = 0; i < 20; i++) {
        vectorPattern.push_back(offset(0, 0, 0.0f));
    }

    return vectorPattern;
}
