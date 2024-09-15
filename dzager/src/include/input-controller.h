#pragma once
#include <string>
#include <vector>

#include "weapon.h"
#include "offset-factory.h"
#include "observer.h"
#include "offset.h"

class InputController {
public:
	InputController(std::string fileName, std::string defaultWeapon);

	std::vector<offset>& getCurrentPattern();

	void getInput();
	void registerObserver(observer<std::vector<offset>>* _observer);

private:
	std::vector<weapon> readWeapons() const;
	void notifyObserver(std::string input, std::vector<offset> &pattern) const;
	void getConsoleInput();
	void getKeyboardInput();
	void reset();

	std::string m_fileName;
	weapon m_currentWeapon;
	observer<std::vector<offset>>* m_observer;
	std::vector<offset> m_currentPattern;
	OffsetFactory m_offsetFactory;
};
