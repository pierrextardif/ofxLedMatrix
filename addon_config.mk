meta:
	ADDON_NAME = ofxLedMatrix
	ADDON_DESCRIPTION = Addon for Led Matrix on Raspberry PI 
	ADDON_AUTHOR = Pierre Tardif
	ADDON_TAGS = "device"
	ADDON_URL = https://github.com/pierrextardif/ofxLedMatrix

<<<<<<< HEAD
linuxarmv7l:	
=======
linuxarmv6l:	
>>>>>>> 58eaec2d4c6d71583f6898cf9bf54c2317a0783a

	RGB_LIB_PATH		=	~/rpi-rgb-led-matrix-master/
	RGB_INCDIR			=	$(RGB_LIB_PATH)/include
	RGB_LIBDIR			=	$(RGB_LIB_PATH)/lib
	RGB_LIBRARY_NAME	=	rgbmatrix
	RGB_LIBRARY 		=	$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

	OFXLEDMATRIX_ROOT 	=	$(OF_ROOT)/addons/ofxLedMatrix/lib/LedMatrix

	ADDON_LDFLAGS 		= 	-W -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -l$(OFXLEDMATRIX_ROOT) -lrt -lm -lpthread
	LIBS				= 	lis3dh.o $(RGB_LIBRARY)
	CXXFLAGS			=	-Wall -Ofast -fomit-frame-pointer -funroll-loops -s -I$(RGB_INCDIR)

#The library is installed in /usr/local/lib
#The header files are in /usr/local/include
#The demos and tools are located in /usr/local/bin
