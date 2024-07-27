#pragma once
#include <ostream>

struct offset {
	offset(float x, float y, float multiplier);
	 
	float x;
	float y;
	float aimMultiplier;
};
