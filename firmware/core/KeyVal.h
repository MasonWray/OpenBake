// KeyVal.h

#ifndef _KEYVAL_h
#define _KEYVAL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Theme.h"
#include "ViewUtils.h"
#include <Adafruit_ILI9341.h>

class KeyVal
{
public:
	KeyVal();
	KeyVal(String _key, String _val, ViewUtils::BoundingBox _bound, float _key_width, Adafruit_ILI9341* _tft);
	~KeyVal();
	void initialize();
	void update();
	void setValue(String new_val);

private:
	Adafruit_ILI9341* tft;
	float key_width;

	String key;
	String val;
	ViewUtils::BoundingBox bound;
	String last_val;
};

#endif

