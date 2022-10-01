// ViewUtils.h

#ifndef _VIEWUTILS_h
#define _VIEWUTILS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"
#include <TouchScreen.h>

namespace ViewUtils
{
	struct BoundingBox
	{
		int16_t x;
		int16_t y;
		uint16_t w;
		uint16_t h;
	};

	String formatf(double val, signed char width, unsigned char prec, char* sout);
	TSPoint* lerp(TSPoint p);

	String mstot(int ms);
}

#endif

