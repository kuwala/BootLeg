#pragma once
#include <Arduino.h>

#define BUTT 35

class Input {
    // Buttons 1-4, Knobs 1-2
    int values[6] = {0,0,0,0,0,0};
    int button1() {
        return values[0];
    }
    void update(){
        values[0]=digitalRead(BUTT);
    }
};