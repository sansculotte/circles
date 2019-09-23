#include <unistd.h>
#include "ofMain.h"
#include "testApp.h"

//--------------------------------------------------------------
int main(int argc, char *argv[]) {

    int opt;
    int width = 1920;
    int height = 1080;
    int resolution = 6;
    int numCircles = NUM_CIRCLES;
    bool record = false;
    bool fullscreen = false;
    bool fill = false;

    while((opt = getopt(argc, argv, "w:h:n:R:rfF")) != -1) {
        switch(opt) {
            case 'w':
                width = atoi(optarg);
                break;
            case 'h':
                height = atoi(optarg);
                break;
            case 'n':
                if (atoi(optarg) <= NUM_CIRCLES && atoi(optarg) > 0) {
                    numCircles = atoi(optarg);
                }
                break;
            case 'R':
                resolution = atoi(optarg);
                break;
            case 'r':
                record = true;
                break;
            case 'f':
                fullscreen = true;
                break;
            case 'F':
                fill = true;
                break;
        }
    }

	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofSetupOpenGL(width, height, fullscreen ? OF_FULLSCREEN : OF_WINDOW);

    testApp* app = new testApp();
    app->record = record;
    app->resolution = resolution;
    app->numCircles = numCircles;
    app->fill = fill;
	ofRunApp(app); // start the app
}
