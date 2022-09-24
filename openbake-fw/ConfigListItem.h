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
#include "ViewUtils.h"
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

class ConfigListItem
{
public:
	ConfigListItem();
	ConfigListItem(ConfigNode* _node, Adafruit_ILI9341* _tft, TouchScreen* _ts, int _i);
	ConfigListItem(Adafruit_ILI9341* _tft, TouchScreen* _ts, int _i);
	~ConfigListItem();
	void initialize();
	bool update();

	ConfigNode* node;
	bool is_back_button;

private:
	Adafruit_ILI9341* tft;
	TouchScreen* ts;
	void drawLeftArrow(Adafruit_ILI9341* _tft, int x, int y);
	void drawRightArrow(Adafruit_ILI9341* _tft, int x, int y);
	void initBoundingBox();

	int i;

	bool is_populated;


	ViewUtils::BoundingBox bound;
	bool pressed;
	int gap;
};

#endif

