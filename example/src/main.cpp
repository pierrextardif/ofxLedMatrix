#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"


//========================================================================
int main( ){

ofSetupOpenGL(WIDTH,HEIGHT, OF_WINDOW);
ofRunApp( new ofApp());

//	ofAppNoWindow window;
//	ofSetupOpenGL(&window,1024,768,OF_WINDOW);
//	ofRunApp(new ofApp);
}
