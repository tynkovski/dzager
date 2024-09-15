#include <iostream>
#include <fstream>
#include <Windows.h>
#include "include/json/json.h"
#include "include/input-controller.h"

InputController::InputController(std::string fileName, std::string defaultWeapon) {
    m_fileName = fileName;
    std::vector<weapon> weapons = readWeapons();
    m_offsetFactory = OffsetFactory(weapons);
    m_currentWeapon = m_offsetFactory.getWeapon(defaultWeapon);
    m_currentPattern = m_offsetFactory.createPattern(m_currentWeapon);
}

std::vector<offset>& InputController::getCurrentPattern() {
    return m_currentPattern;
}

void InputController::getInput() {
    while (true) {
        getConsoleInput();
    }
}

void InputController::getConsoleInput() {
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty()) {
        return;
    }

    if (input == "reset") {
        reset();
        std::cout << "loading " << m_fileName << "\n";
        return;
    }

    try {
        std::vector<offset> pattern = m_offsetFactory.getWeaponPattern(input);
        notifyObserver(input, pattern);
    } catch (const std::invalid_argument& e) {
        std::cout << "not found pattern " << e.what() << "\n";
    }
}

void InputController::getKeyboardInput() {
    if (GetKeyState(VK_LMENU) & 0x8000) {
        std::cout << "! left alt pressed\n";
    }
}

void InputController::registerObserver(observer<std::vector<offset>>* _observer) {
    m_observer = _observer;
}

void InputController::reset() {
    std::vector<weapon> weapons = readWeapons();
    m_offsetFactory = OffsetFactory(weapons);
}

void InputController::notifyObserver(std::string name, std::vector<offset> &pattern) const {
    try {
        if (m_observer != nullptr) {
            m_observer->update(pattern);
            std::cout << "setting up " << name << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "not found pattern " << e.what() << "\n";
    }
}

std::vector<weapon> InputController::readWeapons() const {
    std::ifstream jsonFile(m_fileName);
    std::stringstream jsonBuffer; jsonBuffer << jsonFile.rdbuf();
    std::vector<weapon> weapons = read_weapons_json(jsonBuffer.str());
    return weapons;
}
