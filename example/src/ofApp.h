#pragma once

#include "ofMain.h"
#define COMPUTERWORK

#ifdef COMPUTERWORK

	#define WIDTH 	640
	#define HEIGHT 	640
	

#else

	#define WIDTH 	64
	#define HEIGHT 	64

	#include "LedMatrix.h"

#endif

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		// drawing section
		ofColor backGroundColor;
		ofEasyCam cam;

	#ifdef COMPUTERWORK
		
		ofFbo f;
	
	#else

		LedMatrix ledMatrix;

	#endif

	ofVec3f acceleration;
	int amountPoints;
	ofVboMesh poly;
	vector < ofVec3f > points, increments;
	vector < ofColor > colors;
	vector < ofVec3f > initPolyline(int _width, int _height, vector < ofVec3f >* pol);
	vector < ofVec3f > incrementsInit(int amountPoints);
	vector < ofVec3f > updatePolyline(vector < ofVec3f > pol);
	void updateVbo(vector < ofVec3f > points, ofVboMesh* poly, float distThreshold);
};
