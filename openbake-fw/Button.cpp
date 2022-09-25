// 
// 
// 

#include "Button.h"

Button::Button() {}

Button::Button(String _name, ViewUtils::BoundingBox _bound, Adafruit_ILI9341* _tft, TouchScreen* _ts)
{
	name = _name;
	bound = _bound;
	tft = _tft;
	ts = _ts;
	disabled = false;
	pressed = false;
	gap = 0;

	initialize();
}

Button::~Button()
{
}

void Button::initialize()
{
	using namespace Theme;

	uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;

	tft->getTextBounds(name, bound.x, bound.y, &t_x, &t_y, &t_w, &t_h);
	int text_x = bound.x + ((bound.w - t_w) / 2);
	int text_y = bound.y + (bound.h / 2) + (t_h / 2);

	tft->fillRoundRect(bound.x, bound.y, bound.w, bound.h, radius, bg_accent);
	tft->drawRoundRect(bound.x, bound.y, bound.w, bound.h, radius, border_color);
	tft->setCursor(text_x, text_y);
	tft->print(name);
}

bool Button::update()
{
	return false;
}
