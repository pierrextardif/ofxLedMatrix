#include "ofxLedMatrix.h"


void ofxLedMatrix::setup(int _width, int _height){

	width 	= 	_width;
	height 	= 	_height;

	// LEDs
	memset(&options, 0, sizeof(options));
	options.rows = width;
	options.cols = height;
	//options.chain_length = 2;
	options.hardware_mapping = "adafruit-hat";

#ifdef USE_ACCELEROMETER
	if(lis3dh.begin()) {
		puts("LIS3DH init failed");
	}
#endif

}

void ofxLedMatrix::setChainLength(int _chainLength){
	options.chain_length = _chainLength;
}

void ofxLedMatrix::setParallel(int _parallel){
	options.parallel = _parallel;
}

void ofxLedMatrix::setPWMBits(int _PWMBits){
	options.pwm_bits = _PWMBits;
}

void ofxLedMatrix::setPWMLsbNano(int _PWMLsbNano){
	options.pwm_lsb_nanoseconds = _PWMLsbNano;
}

void ofxLedMatrix::setBrightness(int _brightness){
	options.brightness = _brightness;
}

void ofxLedMatrix::setScanMode(int _scanMode){
	options.scan_mode = _scanMode;
}

void ofxLedMatrix::setRowAddressType(int _rowAddressType){
	options.row_address_type = _rowAddressType;
}

void ofxLedMatrix::setMultiplexing(int _multiplexing){
	options.multiplexing = _multiplexing;
}

void ofxLedMatrix::setLedRgbSequence(char* _rgbSeq){
	options.led_rgb_sequence = _rgbSeq;
}

void ofxLedMatrix::setPixelMapperConfig(char* _pixelMConfig){
	options.pixel_mapper_config = _pixelMConfig;

}

void ofxLedMatrix::setPanelType(char* _panelType){
	options.panel_type = _panelType;

}

void ofxLedMatrix::seLimitRefreshRateHz(int _limitRefreshRateHz){
	options.limit_refresh_rate_hz = _limitRefreshRateHz;
}

void ofxLedMatrix::updateSettingsLedMatrix(){
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
	
	
	// fbo to draw into
	int channels = 3;
	f.allocate(width, height, GL_RGB);
	pixels.allocate(width, height, channels);
	canvasSize = width * height * channels;
}

void ofxLedMatrix::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b){
	led_canvas_set_pixel(canvas, x, y, r,g,b);
}

void ofxLedMatrix::pixelsUpdateMatrixLED(){

#ifdef USE_ACCELEROMETER
	lis3dh.accelRead(&xx, &yy, &zz);
#endif

	led_canvas_clear(canvas);

	ofPixels pixels;
	f.readToPixels(pixels);
	for( uint8_t i =0; i < width; i++){
		for( uint8_t j =0; j < height; j++){

			int indexPixel = (i * height + j) * 4;
			uint8_t pixelRed 	= pixels[indexPixel];
			uint8_t pixelGreen 	= pixels[indexPixel + 1];
			uint8_t pixelBlue 	= pixels[indexPixel + 2];
			led_canvas_set_pixel(canvas,i,j, pixelRed, pixelGreen, pixelBlue);

		}
	}

	canvas = led_matrix_swap_on_vsync(matrix, canvas);
}

// this is way faster
void ofxLedMatrix::textureUpdateMatrixLED(){

    f.readToPixels(pixels);
    pixelLocker.lock();
    setImage(0, 0, (uint8_t*)(pixels.getData()), canvasSize, width, height, 0);
    pixelLocker.unlock();

	canvas = led_matrix_swap_on_vsync(matrix, canvas);
}
