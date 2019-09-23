#pragma once

#define PHI 1.618033
#define _2PI 6.28318530 

#include "ofMain.h"

struct breathingCircle {

    breathingCircle();
    breathingCircle(int pos_x, int pos_y);

    void setup(int resolution, bool fill);
    void update(int target_x, int target_y);
    void draw();
    void drawCircle(); 

    int radius;
    int resolution;
    int size;
    int posX;
    int posY;
    int lineWidth;

    float intensity;
    float speed;
    bool fill;
    int alpha;

};
