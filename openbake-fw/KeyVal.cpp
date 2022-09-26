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
	tft->setCursor(bound.x + (bound.w * key_width), tft->getCursorY());
	tft->print(": ");
	tft->print(val);
}

void KeyVal::update()
{
	using namespace Theme;

	if (!last_val.equals(val))
	{
		tft->setCursor(bound.x, bound.y + bound.h);
		tft->fillRect(bound.x + (bound.w * key_width), bound.y, ((float)bound.w * (1.0 - (float)key_width)), bound.h + 2, background_color);
		tft->setCursor(bound.x + (bound.w * key_width), tft->getCursorY());
		tft->print(": ");
		tft->print(val);
		last_val = val;
	}
}

void KeyVal::setValue(String new_val)
{
	val = new_val;
}
