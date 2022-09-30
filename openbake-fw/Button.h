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
	enum Style
	{
		DEFAULT,
		PRIMARY,
		SUCCESS,
		WARNING,
		DANGER,
	};

	Button();
	Button(String _name, ViewUtils::BoundingBox _bound, Adafruit_ILI9341* _tft, TouchScreen* _ts);
	~Button();

	void initialize();
	bool update();
	void setDisabled(bool is_disabled);
	void setName(String _name);
	void setStyle(Style _style);



private:
	Adafruit_ILI9341* tft;
	TouchScreen* ts;

	String name;
	String last_name;

	Button::Style style;
	Button::Style last_style;

	bool disabled;
	bool last_disabled;

	ViewUtils::BoundingBox bound;
	bool pressed;
	int gap;
};

#endif

