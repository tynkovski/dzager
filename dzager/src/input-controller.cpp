#include <iostream>
#include <Windows.h>

#include "input-controller.h"

InputController::InputController(OffsetFactory *factory) {
    m_offsetFactory = factory;
}

void InputController::getInput() {
    while (true) {        
        getConsoleInput();
    }
}

void InputController::getConsoleInput() {
    std::cout << "> ";
    std::getline(std::cin, m_str);
    notifyObservers();
}

void InputController::getKeyboardInput() {
    if (GetKeyState(VK_LMENU) & 0x8000) {
        std::cout << "! left alt pressed\n";
    }
}

void InputController::registerObserver(observer<std::vector<offset>>* _observer) {
    m_observers.push_back(_observer);
}

void InputController::notifyObservers() const {
    for (auto &o : m_observers) {
        try {
            o->update(m_offsetFactory->getPattern(m_str));
            std::cout << "setting up " << m_str << "\n";
        } catch (const std::invalid_argument& e) {
            std::cout << "not found pattern " << e.what() << "\n";
        }
    }
}
