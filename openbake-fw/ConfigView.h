// ConfigView.h

#ifndef _CONFIGVIEW_h
#define _CONFIGVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Theme.h"
#include "View.h"
#include "ConfigNode.h"

class ConfigView : public View
{
public:
	ConfigView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc);
	~ConfigView();
	void update();
	void initialize();

private:
	ConfigNode* root;
	ConfigNode* node;
};

#endif

