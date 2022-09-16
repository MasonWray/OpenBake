// Utils.h

#ifndef _UTILS_h
#define _UTILS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Utils
{
	struct BoundingBox
	{
		int16_t x;
		int16_t y;
		uint16_t w;
		uint16_t h;
	};

	char* formatf(double val, signed char width, unsigned char prec, char* sout);
}

#endif

