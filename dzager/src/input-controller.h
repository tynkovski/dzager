#pragma once
#include <string>
#include <string>
#include <vector>
#include "offset-factory.h"
#include "observer.h"
#include "offset.h"

class InputController {
public:
	InputController();

	void getInput();
	void registerObserver(observer<std::vector<offset>>* _observer);

	OffsetFactory getOffsetFactory() const;

private:
	std::vector<observer<std::vector<offset>>*> m_observers;
	OffsetFactory m_offsetFactory;
	std::string m_str;

	void notifyObservers() const;
	void getConsoleInput();
	void getKeyboardInput();
};
