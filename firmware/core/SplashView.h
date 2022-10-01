// SplashView.h

#ifndef _SPLASHVIEW_h
#define _SPLASHVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"
#include "Theme.h"
#include "View.h"
#include <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeMono12pt7b.h>
#include <Fonts/FreeMono9pt7b.h>

class SplashView : public View
{
public:
	SplashView(int width, int height, Adafruit_ILI9341* _tft);
	~SplashView();
	void update();
	void initialize();

private:
	int timer;
};

#endif

