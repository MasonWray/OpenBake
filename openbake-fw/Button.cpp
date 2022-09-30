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

	String upper = String(name);
	upper.toUpperCase();

	tft->getTextBounds(upper, bound.x, bound.y, &t_x, &t_y, &t_w, &t_h);
	int text_x = bound.x + ((bound.w - t_w) / 2);
	int text_y = bound.y + (bound.h / 2) + (t_h / 2);

	tft->fillRoundRect(bound.x, bound.y, bound.w, bound.h, radius, bg_accent);
	tft->drawRoundRect(bound.x, bound.y, bound.w, bound.h, radius, border_color);
	tft->setCursor(text_x, text_y);
	tft->print(name);
}

bool Button::update()
{
	using namespace Theme;

	bool selected = false;
	bool rerender = false;

	if (!disabled)
	{
		TSPoint* p = ViewUtils::lerp(ts->getPoint());

		if (p->z > ts->pressureThreshhold)
		{
			if (p->x >= bound.x && p->x <= bound.x + bound.w && p->y >= bound.y && p->y <= bound.y + bound.h)
			{
				rerender = pressed ? rerender : true;
				pressed = true;
				gap = 0;
			}
		}
		else
		{
			if (pressed)
			{
				gap++;
			}

			if (gap > 8 && pressed)
			{
				rerender = true;
				pressed = false;
				selected = true;
			}
		}

		delete p;
	}

	// Check for prop updates
	if (!name.equals(last_name) || style != last_style || disabled != last_disabled)
	{
		rerender = true;
		last_name = name;
		last_style = style;
		last_disabled = disabled;
	}

	if (rerender)
	{
		uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;
		uint16_t bgc = pressed ? bg_selected : bg_accent;

		String upper = String(name);
		upper.toUpperCase();

		tft->getTextBounds(upper, bound.x, bound.y, &t_x, &t_y, &t_w, &t_h);
		int text_x = bound.x + ((bound.w - t_w) / 2);
		int text_y = bound.y + (bound.h / 2) + (t_h / 2);

		tft->fillRoundRect(bound.x, bound.y, bound.w, bound.h, radius, bgc);
		tft->drawRoundRect(bound.x, bound.y, bound.w, bound.h, radius, border_color);
		tft->setCursor(text_x, text_y);
		tft->print(name);
	}

	return selected;
}

void Button::setDisabled(bool is_disabled)
{
	disabled = is_disabled;
}

void Button::setName(String _name)
{
	name = _name;
}

void Button::setStyle(Style _style)
{
	style = _style;
}