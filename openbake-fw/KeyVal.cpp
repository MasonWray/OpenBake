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
	bound = _bound;
	key_width = _key_width;
	tft = _tft;
}

KeyVal::~KeyVal()
{

}

void KeyVal::initialize()
{

}

void KeyVal::update()
{

}

void KeyVal::setValue(String new_val)
{

}
