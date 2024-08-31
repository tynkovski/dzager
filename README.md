# Overwatch 2 and Polygon Recoil Compensator

Project does not use game process, can not be detected by any anti-cheat.

Example of using:
``` C++
vector<offset> createX() {
    vector<offset> pattern;
    for (int i = 0; i < fire; i++) {
        pattern.push_back(offset(offsetX, offsetY, aimModifier));
    }
    for (int i = 0; i < relax; i++) {
        pattern.push_back(offset(offsetX, offsetY, 1.0));
    }
    return pattern;
}
```

- after changing camera offset, there will be delay of 15 milliseconds after which the next offset occurs;
- you can stop offseting if you are reloading or have a burst mode.
