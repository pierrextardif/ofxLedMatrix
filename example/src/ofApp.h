#pragma once

#include "ofMain.h"
// #define COMPUTERWORK

#ifdef COMPUTERWORK

	#define WIDTH 	640
	#define HEIGHT 	640
	

#else

	#define WIDTH 	64
	#define HEIGHT 	64

	#include "LedMatrix/LedMatrix.h"

#endif

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		// drawing section
		ofColor backGroundColor;

	#ifdef COMPUTERWORK
		
		ofFbo f;
	
	#else

		LedMatrix ledMatrix;

	#endif
};
