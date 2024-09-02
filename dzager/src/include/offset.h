#pragma once

struct offset {
	offset(float x, float y, float inScopeMultiplier) {
		this->x = x;
		this->y = y;
		this->inScopeMultiplier = inScopeMultiplier;
	}
	 
	float x;
	float y;
	float inScopeMultiplier;
};