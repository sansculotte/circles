#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
   ofEnableSmoothing();
   ofBackground(0);
   ofSetFrameRate(60);
   ofSetWindowTitle("TESTfixx");
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
            }
         }
      }
      drift_x = (int) sin(circle[i].posY/100) * 5.;
      drift_y = 0;

//      circle[i].update(x, y);
      circle[i].update(circle[j].posX + x + drift_x, circle[j].posY + y + drift_y);
//      circle[i].update(ofGetWidth()/2, ofGetHeight()/2);
//      circle[i].update(ofGetMouseX(), ofGetMouseY());

   }
}

//--------------------------------------------------------------
void testApp::draw(){
   for(int x=0; x<NUM_CIRCLES; x++) {
      circle[x].draw();
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
   distanceSquared = pow(pos_x - circle[index].posX, 2) + pow(pos_y - circle[index].posY, 2);
      if(distanceSquared < pow(tolerance, 2)) {
         return true;
      }
   return false;
}
