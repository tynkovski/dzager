#pragma once
#include <iostream>
#include <Windows.h>

enum class MovementDirection { Left, Right };

class MovementRandomizer {
public:
    MovementRandomizer();
    void doMovement();
private:
    void simulateKeyPress(const WORD& key, const int& delay) const;
    void releaseInput(const WORD& key) const;
    void changeMovement();
    int getMovementCode() const;

    void activate();
    void deactivate();
    
    MovementDirection m_movementDirection;
    bool m_active;
};

