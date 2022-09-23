// ConfigListItem.h

#ifndef _CONFIGLISTITEM_h
#define _CONFIGLISTITEM_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"
#include "Theme.h"
#include "ConfigNode.h"
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

class ConfigListItem
{
public:
	ConfigListItem();
	ConfigListItem(ConfigNode* _node, Adafruit_ILI9341* _tft, TouchScreen* _ts);
	~ConfigListItem();
	void initialize();
	void update();

private:
	Adafruit_ILI9341* tft;
	TouchScreen* ts;
	void drawLeftArrow(int x, int y);
	void drawRightArrow(int x, int y);

	ConfigNode* node;
};

#endif

