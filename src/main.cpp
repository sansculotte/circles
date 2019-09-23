#include <unistd.h>
#include "ofMain.h"
#include "testApp.h"

//--------------------------------------------------------------
int main(int argc, char *argv[]) {

    int opt;
    int width = 1920;
    int height = 1080;
    bool record = false;
    bool fullscreen = false;

    while((opt = getopt(argc, argv, "w:h:rf")) != -1) {
        switch(opt) {
            case 'w':
                width = atoi(optarg);
                ofLog() << "width" << width;
                break;
            case 'h':
                height = atoi(optarg);
                ofLog() << "height" << height;
                break;
            case 'r':
                record = true;
                break;
            case 'f':
                fullscreen = true;
                break;
        }
    }

	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofSetupOpenGL(width, height, fullscreen ? OF_FULLSCREEN : OF_WINDOW);

    testApp* app = new testApp();
    app->record = record;
	ofRunApp(app); // start the app
}
