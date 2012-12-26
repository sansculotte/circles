#include "breathingCircle.h"

breathingCircle::breathingCircle(int pos_x, int pos_y) {
   posX = pos_x % ofGetWidth();
   posY = pos_y % ofGetHeight();
   size = ofRandom(20, 120);
   speed = ofRandom(1, 10) / 10;
//   intensity = ofRandom(10, 100) / 100;
   intensity = 1.;
}

// constructor without position provided
breathingCircle::breathingCircle() {
   posX = ofRandom(0, ofGetWidth()); 
   posY = ofRandom(0, ofGetHeight()); 
   size = ofRandom(20, 150) + pow(2, ofRandom(0, 8));
   speed = ofRandom(1, 10) / 10;
   intensity = ofRandom(10, 100) / 100;
//   intensity = 1.;
}

void breathingCircle::update(int target_x, int target_y) {

   radius = pow(sin(ofGetElapsedTimef() * speed),3) * size;

//   posX += abs(target_x - posX) * radius / 5000;
//   posY += abs(target_y - posY) * radius / 5000;
//   int deltaX = target_x - posX;
//   int deltaY = target_y - posY;
   float target;
   float current;
   target = radius / 10000.;
   current = 1. - target;
//   posX += (deltaX > 0 ? 1 : -1) * abs(target_x - posX) * radius / 5000;
//   posY += (deltaY > 0 ? 1 : -1) * abs(target_y - posY) * radius / 5000;
   posX = posX * current + target_x * target + 2;
   posY = posY * current + target_y * target + 2;

   posX = posX % (ofGetWidth()+1);
   posY = posY % (ofGetHeight()+1);
}

void breathingCircle::draw() {
//   ofSetColor(intensity*255, 0, 0);
   ofSetColor(intensity*255, intensity*255, intensity*255);
   ofNoFill();
   ofCircle(posX, posY, radius);
   //ofRectangle(posX - radius/2 , posY - radius/2, radius, radius);
}
