#pragma once

#define PHI 1.618033
#define _2PI 6.28318530 

#include "ofMain.h"

class breathingCircle{
   public:

      breathingCircle();
      breathingCircle(int pos_x, int pos_y);

      void update(int target_x, int target_y);
      void draw();

      int radius;
      int size;
      int posX;
      int posY;
      int lineWidth;

      float intensity;
      float speed;

};
