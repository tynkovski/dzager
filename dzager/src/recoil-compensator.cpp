#include "include/recoil-compensator.h"

#include <iostream>
#include <string>
#include <thread>

#define DELAY 16

void RecoilCompensator::update(const std::vector<offset> &pattern)  {
	setPattern(pattern);
}

RecoilCompensator::RecoilCompensator(float recoilFactor, const std::vector<offset> &pattern) {
	m_recoilFactor = recoilFactor;
	m_pattern      = pattern;
	m_tick         = 0;
}

void RecoilCompensator::compensateRecoil() {
	while (true) {
		while (GetAsyncKeyState(VK_LBUTTON) && m_tick < m_pattern.size()) {
			float multiplier = GetAsyncKeyState(VK_RBUTTON) 
				? m_pattern[m_tick].inScopeMultiplier 
				: 1.f;

			long y = long(m_pattern[m_tick].y * m_recoilFactor * multiplier);
			long x = long(m_pattern[m_tick].x * m_recoilFactor * multiplier);

			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);

			std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
			m_tick++;
		}

		m_tick = 0;
	}
}

void RecoilCompensator::setPattern(const std::vector<offset>& pattern) {
	m_tick    = 0;
	m_pattern = pattern;
}
