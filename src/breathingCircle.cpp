#include "breathingCircle.h"


breathingCircle::breathingCircle(int pos_x, int pos_y) {
    posX = pos_x % ofGetWidth();
    posY = pos_y % ofGetHeight();
}

// constructor without position provided
breathingCircle::breathingCircle() {
    posX = ofRandom(0, ofGetWidth());
    posY = ofRandom(0, ofGetHeight());
}

void breathingCircle::setup(int resolution=6, bool fill=false) {
    size = ofRandom(20, 150) + pow(2, ofRandom(0, 8));
    speed = ofRandom(1, 10) / 10;
    intensity = pow(ofRandom(0, 100) / 100,2);
    lineWidth = ofRandom(1, 3);
    this->resolution = resolution;
    this->fill = fill && ofRandom(0, 100) > 90;
    if (this->fill) {
        this->alpha = ofRandom(0, 127);
    }
}

void breathingCircle::update(int target_x, int target_y) {

    radius = pow(sin(ofGetElapsedTimef() * speed), 3) * size;

    //   posX += abs(target_x - posX) * radius / 5000;
    //   posY += abs(target_y - posY) * radius / 5000;
    //   int deltaX = target_x - posX;
    //   int deltaY = target_y - posY;
    float target;
    float current;
#ifdef SPEED_FROM_SIZE
    target = size / 10000.;
#else
    target = radius / 10000.; // that mekes for weird movements
#endif
    current = 1. - target;
    //   posX += (deltaX > 0 ? 1 : -1) * abs(target_x - posX) * radius / 5000;
    //   posY += (deltaY > 0 ? 1 : -1) * abs(target_y - posY) * radius / 5000;
    posX = posX * current + target_x * target + 1;
    posY = posY * current + target_y * target + 1;

    posX = posX % ofGetWidth();
    posY = posY % ofGetHeight();
}

void breathingCircle::drawCircle() {
    ofSetLineWidth(lineWidth);
    ofSetCircleResolution(resolution);
    ofDrawCircle(posX, posY, radius);
}

void breathingCircle::draw() {
    if (fill) {
        ofEnableAlphaBlending();
        ofSetColor(intensity*255, intensity*255, intensity*255, alpha);
        ofFill();
        drawCircle();
        ofDisableAlphaBlending();
    }
    else {
        ofNoFill();
        ofSetColor(intensity*255, intensity*255, intensity*255);
        drawCircle();
    }
    //   ofRect(posX - radius/2 , posY - radius/2, PHI*radius, radius);
}
