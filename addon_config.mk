meta:
	ADDON_NAME = ofxLedMatrix
	ADDON_DESCRIPTION = Addon for Led Matrix on Raspberry PI 
	ADDON_AUTHOR = Pierre Tardif
	ADDON_TAGS = "device"
	ADDON_URL = https://github.com/pierrextardif/ofxLedMatrix

linuxarmv6l:

	#copy the path here :
	RGB_LIB_PATH=/home/pi/rpi-rgb-led-matrix/
	RGB_INCDIR=$(RGB_LIB_PATH)/include
	RGB_LIBDIR=$(RGB_LIB_PATH)/lib
	RGB_LIBRARY_NAME=rgbmatrix
	RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a



	ADDON_LIBS = lis3dh.o $(RGB_LIBRARY)
	ADDON_CFLAGS = -Wall -Ofast -fomit-frame-pointer -funroll-loops -s -I$(RGB_INCDIR)

	ADDON_INCLUDES = $(OF_ROOT)/addons/ofxLedMatrix/src/