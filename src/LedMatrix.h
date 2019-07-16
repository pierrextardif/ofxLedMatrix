#pragma once

#include "ofMain.h"

#include "led-matrix-c.h"
#include "lis3dh.h"
#include <signal.h>

class LedMatrix{
	public : 

	LedMatrix(){

	}

	void setup(int _width, int _height);
	void updateMatrixLED();


	struct RGBLedMatrix 		*matrix  = NULL;
	struct RGBLedMatrixOptions 	options;
	struct LedCanvas          	*canvas;

	// accelerometer
	Adafruit_LIS3DH      lis3dh;
	int xx, yy, zz;

	int width, height;

	// fbo Stuff
	ofFbo f;
	void begin(){f.begin();}
	void end(){f.end();}


};