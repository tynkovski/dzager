#pragma once
#include "observer.h"
#include "offset.h"

#include <vector>
#include <Windows.h>

class RecoilCompensator : public observer<std::vector<offset>> {
public:
    RecoilCompensator(float recoilFactor, const std::vector<offset>& pattern);

    void update(const std::vector<offset> &pattern);
    void compensateRecoil();
    void setPattern(const std::vector<offset>& pattern);

private:
    float m_recoilFactor;
    float m_tick;
    std::vector<offset> m_pattern;
};
