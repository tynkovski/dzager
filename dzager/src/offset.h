#pragma once
#include <ostream>

struct offset {
	offset(float x, float y, float multiplier) {
		this->x = x;
		this->y = y;
		aimMultiplier = multiplier;
	}
	 
	float x;
	float y;
	float aimMultiplier;
};
