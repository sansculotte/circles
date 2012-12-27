#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   ofEnableSmoothing();
   ofBackground(0);
   ofSetFrameRate(60);
   ofSetWindowTitle("TESTfixx");
//   ofSetWindowDimension(1280, 720);
   record = false;
//   for(int x=0; x<NUM_CIRCLES; x++) {
//      circle[x] = new breathingCircle();
//   }
}

//--------------------------------------------------------------
void testApp::update(){

   int i, j, x, y, drift_x, drift_y;

   for(i=0; i<NUM_CIRCLES; i++) {
      x=0;
      y=0;
      // find next biggest
      bool haveTarget=false;
      if((int) ofRandom(1, 10) == 5) {
         x = ofRandom(0, circle[i].size) - circle[i].size / 2; 
         y = ofRandom(0, circle[i].size) - circle[i].size / 2; 
      } else {
         for (j=0; j<NUM_CIRCLES && ! haveTarget; j++) {
            if(i!=j) {
               haveTarget = closeEnough(i, circle[j].posX, circle[j].posY, circle[j].size);
               if(abs(circle[j].posX-circle[i].posX)<10 && abs(circle[j].posX-circle[i].posX)<10) {
                  circle[i].posX=ofRandom(0, ofGetWidth());
                  circle[i].posY=ofRandom(0, ofGetHeight());
               }
               x=circle[j].posX;
               y=circle[j].posY;
            }
         }
      }
      drift_x = (int) pow(sin(circle[i].posY/100), 2);
      drift_y = 0;

//      circle[i].update(x, y);
      circle[i].update( x + drift_x, y + drift_y);
//      circle[i].update(ofGetWidth()/2, ofGetHeight()/2);
//      circle[i].update(ofGetMouseX(), ofGetMouseY());

   }
}

//--------------------------------------------------------------
void testApp::draw(){
   char fileName[36];
   for(int x=0; x<NUM_CIRCLES; x++) {
      circle[x].draw();
   }
   if(record) {
      sprintf(fileName, "frame_%04u.png", ofGetFrameNum());
      ofSaveScreen(ofFilePath::join(ofFilePath::getPathForDirectory(SAVE_PATH), fileName));
   }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
   if(key == 32) {
      for(int i=0; i<NUM_CIRCLES; i++) {
         circle[i].posX = ofRandom(0, ofGetWidth());
         circle[i].posY = ofRandom(0, ofGetWidth());
      }
   }
   if(key == 'r') {
      record = true;
   } else if(key == 'R') {
      record = false;
   }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

// methods for accessing the particle system from a particle
bool testApp::closeEnough(int index, int pos_x, int pos_y, float tolerance) {
   float distanceSquared;
   distanceSquared = ofDistSquared(pos_x, pos_y, circle[index].posX, circle[index].posY);
   //distanceSquared = pow(pos_x - circle[index].posX, 2) + pow(pos_y - circle[index].posY, 2);
      if(distanceSquared < pow(tolerance, 2)) {
         return true;
      }
   return false;
}
