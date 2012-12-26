#ifndef _BREATHING_CIRLCE
#define _BREATHING_CIRLCE
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

      float intensity;
      float speed;

};

#endif
