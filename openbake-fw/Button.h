// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Theme.h"
#include "ViewUtils.h"
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

class Button
{
public:
	Button();
	Button(String _name, ViewUtils::BoundingBox _bound, Adafruit_ILI9341* _tft, TouchScreen* _ts);
	~Button();

	void initialize();
	bool update();

private:
	Adafruit_ILI9341* tft;
	TouchScreen* ts;

	String name;
	ViewUtils::BoundingBox bound;
	bool disabled;
	bool pressed;
	int gap;
};

#endif

