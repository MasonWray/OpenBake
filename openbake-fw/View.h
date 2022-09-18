// View.h

#ifndef _VIEW_h
#define _VIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "ViewUtils.h"

class View
{
public:
	enum ViewType
	{
		MAIN_VIEW,
	};

	virtual ViewType update();
	virtual void initialize();
	static void updateCurrentView(ViewType new_view, View* cur_view);
};


#endif

