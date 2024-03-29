#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   ofEnableSmoothing();
   ofBackground(0);
   ofSetFrameRate(60);
   ofSetWindowTitle("circles");
   for(int x=0; x<numCircles; x++) {
      circle[x].setup(this->resolution, this->fill);
   }
}

//--------------------------------------------------------------
void ofApp::update(){

   int i, j, x, y, drift_x, drift_y;

   for(i=0; i<numCircles; i++) {
      x=0;
      y=0;
      // find next biggest
      bool haveTarget = false;
      if((int) ofRandom(1, 10) == 5) {
         x = ofRandom(0, circle[i].size) - circle[i].size / 2; 
         y = ofRandom(0, circle[i].size) - circle[i].size / 2; 
      } else {
         for (j=0; j<numCircles && ! haveTarget; j++) {
            if(i != j) {
               haveTarget = closeEnough(i, circle[j].posX, circle[j].posY, circle[j].size);
#ifndef SPEED_FROM_SIZE 
               if(abs(circle[j].posX-circle[i].posX)<10 && abs(circle[j].posX-circle[i].posX)<10) {
                  circle[i].posX = ofRandom(0, ofGetWidth());
                  circle[i].posY = ofRandom(0, ofGetHeight());
               }
#endif
               x = circle[j].posX;
               y = circle[j].posY;
            }
         }
      }
      drift_x = (int) pow(sin(circle[i].posY/100), 2);
      drift_y = 0;

//      circle[i].update(x, y);
      circle[i].update(x + drift_x, y + drift_y);
//      circle[i].update(ofGetWidth()/2, ofGetHeight()/2);
//      circle[i].update(ofGetMouseX(), ofGetMouseY());

   }
}

//--------------------------------------------------------------
void ofApp::draw(){
   char fileName[36];
   for(int x=0; x<numCircles; x++) {
      circle[x].draw();
   }
   if(record) {
      sprintf(fileName, "frame_%04u.png", ofGetFrameNum());
      ofSaveScreen(ofFilePath::join(ofFilePath::getPathForDirectory(SAVE_PATH), fileName));
   }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   if(key == 32) {
      for(int i=0; i<numCircles; i++) {
         circle[i].posX = ofRandom(0, ofGetWidth());
         circle[i].posY = ofRandom(0, ofGetWidth());
      }
   }
   if(key == 'r') {
      record = true;
   } else if(key == 'R') {
      record = false;
   } else if(key == 'q' || key == 27) {
      ofExit();
   }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// methods for accessing the particle system from a particle
bool ofApp::closeEnough(int index, int pos_x, int pos_y, float tolerance) {
   float distanceSquared;
   distanceSquared = ofDistSquared(pos_x, pos_y, circle[index].posX, circle[index].posY);
   //distanceSquared = pow(pos_x - circle[index].posX, 2) + pow(pos_y - circle[index].posY, 2);
      if(distanceSquared < pow(tolerance, 2)) {
         return true;
      }
   return false;
}
