#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(100);
	ofSetLogLevel(OF_LOG_ERROR);	
	ofSetVerticalSync(true);
	backGroundColor = ofColor::fuchsia;


	#ifdef COMPUTERWORK
		
		f.allocate(WIDTH, HEIGHT, GL_RGBA);
	
	#else
	
		ledMatrix.setup(WIDTH, HEIGHT);
	
	#endif


}

//--------------------------------------------------------------
void ofApp::update(){

	#ifdef COMPUTERWORK
		f.begin();
	#else
		ledMatrix.begin();
	#endif

		ofClear(0,0);
		ofBackground(backGroundColor);

		ofPushMatrix();
		ofSetColor(100, 100, 2000);
		ofRotateZ(ofGetElapsedTimef());
		ofDrawRectangle(0,0,100,100);
		ofPopMatrix();
	
	#ifdef COMPUTERWORK
			f.end();
		#else
			ledMatrix.end();
			ledMatrix.updateMatrixLED();
	#endif

}

//--------------------------------------------------------------
void ofApp::draw(){

#ifdef COMPUTERWORK
	
	f.draw(0,0);

#endif
}