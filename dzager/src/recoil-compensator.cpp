#include "recoil-compensator.h"

RecoilCompensator::RecoilCompensator(const float& recoilFactor, const std::vector<offset> &pattern) {
	m_recoilFactor = recoilFactor;
	m_pattern = pattern;
}

void RecoilCompensator::compensateRecoil() const {
	int tick = 0;

	while (true) {
		while (GetAsyncKeyState(VK_LBUTTON) && tick < m_pattern.size()) {
			float multiplier = 1.f;
			if (GetAsyncKeyState(VK_RBUTTON)) {
				multiplier = m_pattern[tick].aimMultiplier;
			}
			else {
				multiplier = 1.f;
			}

			long y = long(m_pattern[tick].y * m_recoilFactor * multiplier);
			long x = long(m_pattern[tick].x * m_recoilFactor * multiplier);

			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);

			std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
			tick++;
		}

		tick = 0;
	}
}

std::vector<offset> RecoilCompensator::getPattern() const {
	return m_pattern;
}

void RecoilCompensator::setPattern(const std::vector<offset>& pattern) {
	m_pattern = pattern;
}
