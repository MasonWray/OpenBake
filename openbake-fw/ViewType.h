// ViewType.h

#ifndef _VIEWTYPE_h
#define _VIEWTYPE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Display
{
	enum ViewType
	{
		MAIN_VIEW,
	};
}

#endif

