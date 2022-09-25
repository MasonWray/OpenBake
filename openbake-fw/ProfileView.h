// ProfileView.h

#ifndef _PROFILEVIEW_h
#define _PROFILEVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "View.h"
#include "Theme.h"
#include "Button.h"

class ProfileView : public View
{
public:
	ProfileView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, AppState* _state);
	~ProfileView();

	void initialize();
	void update();

private:
	Button test;
};

#endif

