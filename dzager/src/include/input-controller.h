#pragma once
#include <string>
#include <vector>

#include "offset-factory.h"
#include "observer.h"
#include "offset.h"

class InputController {
public:
	InputController(OffsetFactory* factory);

	void getInput();
	void registerObserver(observer<std::vector<offset>>* _observer);

private:
	std::vector<observer<std::vector<offset>>*> m_observers;
	std::string m_str;
	OffsetFactory* m_offsetFactory;

	void notifyObservers() const;
	void getConsoleInput();
	void getKeyboardInput();
};
