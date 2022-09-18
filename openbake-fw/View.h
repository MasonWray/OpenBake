// View.h

#ifndef _VIEW_h
#define _VIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "ViewUtils.h"
#include <Arduino.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <Adafruit_MAX31855.h>

class View
{
public:
	enum ViewType
	{
		MAIN_VIEW,
		CONFIG_VIEW,
	};

	ViewType type;
	int display_width;
	int display_height;

	Adafruit_ILI9341* tft;
	TouchScreen* ts;
	Adafruit_MAX31855* tc;

	ViewType next_view;
	virtual void update();
	virtual void initialize();
	static void updateCurrentView(ViewType new_view, View* cur_view);
};


#endif

