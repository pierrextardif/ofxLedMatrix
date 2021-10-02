#pragma once

// #define USE_ACCELEROMETER

#include "ofMain.h"

#include "led-matrix-c.h"
#ifdef USE_ACCELEROMETER
	#include "lis3dh/lis3dh.h"
#endif
#include <signal.h>

class ofxLedMatrix{
	public : 

	ofxLedMatrix(){

	}

	void setup(int _width, int _height);

	void setChainLength(int _chainLength);
	void setParallel(int _parallel);
	void setPWMBits(int _PWMBits);
	void setPWMLsbNano(int _PWMLsbNano);
	void setBrightness(int _brightness);
	void setScanMode(int _scanMode);
	void setPWMDithBits(int _PWMDithBits);
	void setRowAddressType(int _rowAddressType);
	void setMultiplexing(int _multiplexing);
	void setLedRgbSequence(char* _rgbSeq);
	void setPixelMapperConfig(char* _pixelMConfig);
	void setPanelType(char* _panelType);
	void seLimitRefreshRateHz(int _limitRefreshRateHz);



	void pixelsUpdateMatrixLED();
	void textureUpdateMatrixLED();
	void updateSettingsLedMatrix();


	struct RGBLedMatrix 		*matrix  = NULL;
	struct RGBLedMatrixOptions 	options;
	struct LedCanvas          	*canvas;

#ifdef USE_ACCELEROMETER
	// accelerometer
	Adafruit_LIS3DH      lis3dh;
	int xx, yy, zz;
#endif

	int width, height;
	std::mutex pixelLocker;
	ofPixels pixels;
	size_t canvasSize;

	// fbo Stuff
	ofFbo f;
	void begin(){f.begin();}
	void end(){f.end();}

	void setImage(int canvas_offset_x, int canvas_offset_y,
               const uint8_t *image_buffer, size_t buffer_size_bytes,
               int image_width, int image_height,
               char is_bgr){
				set_image(canvas, canvas_offset_x, canvas_offset_y,
               image_buffer, buffer_size_bytes,
            	image_width, image_height,
                is_bgr);
                canvas = led_matrix_swap_on_vsync(matrix, canvas);
	}
	
	void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
	void updateCanvas();
	

};
