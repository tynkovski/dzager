#include "movement-randomizer.h"

#include <vector>
#include <thread>

MovementRandomizer::MovementRandomizer() {
    m_movementDirection = MovementDirection::Left;
    m_active = false;
}

inline void keyDown(INPUT& input, const WORD& key) {
    input.ki.wVk = key;
    SendInput(1, &input, sizeof(INPUT));
}

inline void keyUp(INPUT& input) {
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void MovementRandomizer::doMovement() {
    while (true) {
        while (GetAsyncKeyState(VK_LBUTTON)) {
            simulateKeyPress(getMovementCode(), 90);
            changeMovement();
        }
    }
}

inline void MovementRandomizer::simulateKeyPress(const WORD& key, const int& delay) const {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    keyDown(input, key);

    std::this_thread::sleep_for(std::chrono::milliseconds(delay));

    keyUp(input);
}

inline void MovementRandomizer::releaseInput(const WORD& key) const {
    INPUT input = { 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;

    keyUp(input);
}

void MovementRandomizer::changeMovement() {
    m_movementDirection = (m_movementDirection == MovementDirection::Left) 
        ? MovementDirection::Right
        : MovementDirection::Left;
}

int MovementRandomizer::getMovementCode() const {
    return m_movementDirection == MovementDirection::Left ? 0x41 : 0x44;
}

void MovementRandomizer::activate() {
    m_active = true;
}

void MovementRandomizer::deactivate() {
    m_active = false;
}