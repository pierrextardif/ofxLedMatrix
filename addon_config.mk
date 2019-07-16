meta:
	ADDON_NAME = ofxLedMatrix
	ADDON_DESCRIPTION = Addon for Led Matrix on Raspberry PI 
	ADDON_AUTHOR = Pierre Tardif
	ADDON_TAGS = "device"
	ADDON_URL = https://github.com/pierrextardif/ofxLedMatrix

linuxarmv7l:	
	
	ADDON_LDFLAGS 		= 	-L/usr/local/lib/ -L/usr/local/cuda/lib64
	RGB_LIB_PATH		=	~/rpi-rgb-led-matrix-master/
	RGB_INCDIR			=	$(RGB_LIB_PATH)/include
	RGB_LIBDIR			=	$(RGB_LIB_PATH)/lib
	RGB_LIBRARY_NAME	=	rgbmatrix
	RGB_LIBRARY 		=	$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

	ADDON_LDFLAGS 		= 	-W -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -lrt -lm -lpthread
	LIBS				= 	lis3dh.o $(RGB_LIBRARY)
	CXXFLAGS			=	-Wall -Ofast -fomit-frame-pointer -funroll-loops -s -I$(RGB_INCDIR)


#The library is installed in /usr/local/lib
#The header files are in /usr/local/include
#The demos and tools are located in /usr/local/bin
