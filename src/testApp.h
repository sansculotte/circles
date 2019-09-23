#pragma once

#include "ofMain.h"
#include "breathingCircle.h"

#define NUM_CIRCLES 2000
#define SAVE_PATH "/tmp"
#define OSC_CONTROL
#define SPEED_FROM_SIZE

struct testApp : public ofBaseApp {
    int radius;
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // methods for accessing particle system
    bool closeEnough(int index, int pos_x, int pos_y, float tolerance);

    breathingCircle circle[NUM_CIRCLES];

    bool record;
    int resolution;
    int numCircles;
    bool fill;

};
