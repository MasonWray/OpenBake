// View.h

#ifndef _VIEW_h
#define _VIEW_h

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

	class View
	{
	public:
		virtual void update();
	};
}

#endif

