#pragma once
#include <Arduino.h>

// Button Pins 24, 25 are for DMG-1 version
#define BUTT1 24
#define BUTT2 25

class Input {
    // Buttons 1-4, Knobs 1-2
    int values[6] = {0,0,0,0,0,0};
    public:
    Input() {

    }
    int getButton(int i) {
        return values[i];
    }
    void begin() {
        pinMode(BUTT1, INPUT_PULLUP);
        pinMode(BUTT2, INPUT_PULLUP);
    }
    void update(){
        values[0]=digitalRead(BUTT1);
        values[1]=digitalRead(BUTT2);
    }
};