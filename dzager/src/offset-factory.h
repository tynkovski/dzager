#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "observer.h"
#include "offset.h"

#define DEFAULT_PATTERN "ak12"

class OffsetFactory {
public:
    OffsetFactory();

    std::vector<offset> getDefault();
    std::vector<offset> getPattern(const std::string &str) const;

    std::vector<offset> createSoldier();
    std::vector<offset> createBaptist();

    std::vector<offset> createAk12();
    std::vector<offset> createVector();
    std::vector<offset> createAk308();
    std::vector<offset> createAk74m();
    std::vector<offset> createG36();

private:
    std::unordered_map<std::string, std::vector<offset>> m_offsetTable;
};
