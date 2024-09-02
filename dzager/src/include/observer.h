#pragma once

template <typename T>
class observer {
public:
	virtual void update(const T &val) = 0;
};
