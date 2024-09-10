#pragma once
#include <string>
#include <vector>

#include "weapon.h"
#include "offset-factory.h"
#include "observer.h"
#include "offset.h"

class InputController {
public:
	InputController(std::string defaultWeapon);

	void getInput();
	void registerObserver(observer<std::vector<offset>>* _observer);

private:
	std::vector<weapon> readWeapons() const;
	void notifyObserver(std::string input, std::vector<offset> &pattern) const;
	void getConsoleInput();
	void getKeyboardInput();
	void reset();

	observer<std::vector<offset>>* m_observer;
	OffsetFactory m_offsetFactory;

	weapon m_currentWeapon;
};
