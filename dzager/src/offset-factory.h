#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "observer.h"
#include "offset.h"

class OffsetFactory {
public:
    OffsetFactory();

    std::vector<offset> getPattern(const std::string &str) const;

    std::vector<offset> createSoldier();
    std::vector<offset> createBaptist();

    std::vector<offset> createAk12();
    std::vector<offset> createVector();
    std::vector<offset> createAk308();
    std::vector<offset> createAk74m();
    std::vector<offset> createVal();
    std::vector<offset> createG36();

private:
    std::unordered_map<std::string, std::vector<offset>> m_offsetTable;
};
