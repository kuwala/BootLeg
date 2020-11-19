#include "Input.h"

class Snake {
    private:
        int x;
        int y;
        const static int maxLength = 100;
        int length = 1;
        int xs[maxLength];
        int ys[maxLength];

    Snake(int startX, int startY) {
        xs[1]= startX;
        ys[1] = startY;

    }
    void update(Input& input) {
    
        if(input.button1() == 1) {

        }
    }
};