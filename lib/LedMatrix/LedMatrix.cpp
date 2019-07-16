#include "LedMatrix.h"


void LedMatrix::setup(int _width, int _height){

	width 	= 	_width;
	height 	= 	_height;

	// LEDs
	memset(&options, 0, sizeof(options));
	options.rows = width;
	options.cols = height;
	options.chain_length = 1;
	options.hardware_mapping = "adafruit-hat";

	// init 
	led_matrix_delete(matrix);
	matrix = NULL;

	int sig[] = { SIGHUP,SIGINT,SIGQUIT,SIGABRT,SIGKILL,SIGBUS,SIGSEGV,SIGTERM };
	int N_SIGNALS = (int)(sizeof sig / sizeof sig[0]);
	for(int i=0; i<N_SIGNALS; i++) signal(sig[i], NULL);

	matrix = led_matrix_create_from_options(&options, NULL, NULL);

	// Create offscreen canvas for double-buffered animation
	canvas = led_matrix_create_offscreen_canvas(matrix);
	led_canvas_get_size(canvas, &width, &height);
	cout << "Size : \n width = " << ofToString(width) << "\n height = "<< ofToString(height) << endl;
	cout << " Hardware gpio mapping : " << ofToString(options.hardware_mapping) << endl;
	if(lis3dh.begin()) {
		puts("LIS3DH init failed");
	}

	// fbo to draw into
	f.allocate(width, height, GL_RGBA);

}

void LedMatrix::updateMatrixLED(){
	lis3dh.accelRead(&xx, &yy, &zz);

	led_canvas_clear(canvas);
	ofPixels pixels;
	f.readToPixels(pixels);
	for( uint8_t i =0; i < 64; i++){
		for( uint8_t j =0; j < 64; j++){

			int indexPixel = (i * 64 + j) * 4;
			uint8_t pixelRed 	= pixels[indexPixel];
			uint8_t pixelGreen 	= pixels[indexPixel + 1];
			uint8_t pixelBlue 	= pixels[indexPixel + 2];
			led_canvas_set_pixel(canvas,i,j, pixelRed, pixelGreen, pixelBlue);

		}
	}

	canvas = led_matrix_swap_on_vsync(matrix, canvas);
}