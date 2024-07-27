#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <thread>
#include <Windows.h>
#include "offset.h"

static const int DELAY = 16;

class RecoilCompensator {
public:
    RecoilCompensator(const float& recoilFactor, const std::vector<offset>& pattern);
    void compensateRecoil() const;
    void setPattern(const std::vector<offset>& pattern);
    std::vector<offset> getPattern() const;
private:
    float m_recoilFactor;
    std::vector<offset> m_pattern;
};
