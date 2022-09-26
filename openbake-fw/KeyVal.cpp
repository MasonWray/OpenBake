// 
// 
// 

#include "KeyVal.h"

KeyVal::KeyVal()
{

}

KeyVal::KeyVal(String _key, String _val, ViewUtils::BoundingBox _bound, float _key_width, Adafruit_ILI9341* _tft)
{
	key = _key;
	val = _val;
	last_val = _val;
	bound = _bound;
	key_width = _key_width;
	tft = _tft;

	initialize();
}

KeyVal::~KeyVal()
{

}

void KeyVal::initialize()
{
	tft->setCursor(bound.x, bound.y + bound.h);
	tft->print(key);
}

void KeyVal::update()
{
	if (!last_val.equals(val))
	{

	}
}

void KeyVal::setValue(String new_val)
{
	val = new_val;
}
