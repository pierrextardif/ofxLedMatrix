meta:
	ADDON_NAME = ofxLedMatrix
	ADDON_DESCRIPTION = Addon for Led Matrix on Raspberry PI 
	ADDON_AUTHOR = Pierre Tardif
	ADDON_TAGS = "device"
	ADDON_URL = https://github.com/pierrextardif/ofxLedMatrix

linuxarmv7l:

	# RGB_LIB_PATH		=	~/rpi-rgb-led-matrix-master/
	# RGB_INCDIR			=	$(RGB_LIB_PATH)/include
	# RGB_LIBDIR			=	$(RGB_LIB_PATH)/lib
	# RGB_LIBRARY_NAME	=	rgbmatrix
	# RGB_LIBRARY 		=	$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

	# OFXLEDMATRIX_ROOT 	=	$(OF_ROOT)/addons/ofxLedMatrix/src/

	# LIBS				= 	lis3dh.o $(RGB_LIBRARY)
	# #ADDON_LDFLAGS 		= 	-W -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -L$(OFXLEDMATRIX_ROOT) -lrt -lm -lpthread
	# ADDON_LDFLAGS 		= 	-W -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) -L$(OFXLEDMATRIX_ROOT) -lrt -lm -lpthread

	# CXXFLAGS			=	-Wall -Ofast -fomit-frame-pointer -funroll-loops -s -I$(RGB_INCDIR)


	#OFXRPILED_ROOT = $(OF_ROOT)/addons/ofxRpiLED/libs/rgb_matrix
	#ADDON_LDFLAGS = $(OFXRPILED_ROOT)/lib/linux/librgbmatrix.a  -lrt -lm -lpthread

#The library is installed in /usr/local/lib
#The header files are in /usr/local/include
#The demos and tools are located in /usr/local/bin


	# OFXLEDMATRIX_ROOT = $(OF_ROOT)/addons/ofxLedMatrix/src
	# ADDON_LDFLAGS = $(OFXRPILED_ROOT)  -lrt -lm -lpthread	
