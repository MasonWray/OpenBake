// 
// 
// 

#include "ConfigListItem.h"

using namespace Theme;

ConfigListItem::ConfigListItem()
{
	is_populated = false;
}

ConfigListItem::ConfigListItem(ConfigNode* _node, Adafruit_ILI9341* _tft, TouchScreen* _ts, int _i)
{
	node = _node;
	tft = _tft;
	ts = _ts;
	i = _i;

	is_back_button = false;
	is_populated = true;

	pressed = false;
	gap = 0;

	initBoundingBox();
	initialize();
}

ConfigListItem::ConfigListItem(Adafruit_ILI9341* _tft, TouchScreen* _ts, int _i)
{
	tft = _tft;
	ts = _ts;
	i = _i;

	is_back_button = true;
	is_populated = true;

	pressed = false;
	gap = 0;

	initBoundingBox();
	initialize();
}

ConfigListItem::~ConfigListItem()
{

}

void ConfigListItem::initBoundingBox()
{
	bound.w = W;
	bound.h = H / ITEMS_PER_PAGE;
	bound.x = 0;
	bound.y = i * bound.h;
}

void ConfigListItem::initialize()
{
	uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;
	String name = is_back_button ? "Back" : node->name;

	int line_y = bound.y + bound.h;
	tft->drawFastHLine(0, line_y, W, border_color);
	tft->getTextBounds(name, 0, H, &t_x, &t_y, &t_w, &t_h);
	int text_x = left_offset;
	int text_y = line_y - (bound.h / 2) + (t_h / 2);
	tft->setCursor(text_x, text_y);
	tft->println(name);

	if (is_back_button)
	{
		drawLeftArrow(tft, padding, bound.h / 2);
	}
	else if (!node->exit_node)
	{
		drawRightArrow(tft, W - padding, line_y - (bound.h / 2));
	}
}

void ConfigListItem::update()
{
	if (is_populated)
	{
		bool rerender = false;
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
			}
		}

		delete p;

		if (rerender)
		{
			uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;
			String name = is_back_button ? "Back" : node->name;
			uint16_t bgc = pressed ? bg_selected : background_color;

			tft->fillRect(bound.x, bound.y, bound.w, bound.h, bgc);
			int line_y = bound.y + bound.h;

			tft->getTextBounds(name, 0, H, &t_x, &t_y, &t_w, &t_h);
			int text_x = left_offset;
			int text_y = line_y - (bound.h / 2) + (t_h / 2);
			tft->setCursor(text_x, text_y);
			tft->println(name);
			tft->drawFastHLine(0, line_y, W, border_color);
			if (i > 0)
			{
				tft->drawFastHLine(0, bound.y, W, border_color);
			}
			if (is_back_button)
			{
				drawLeftArrow(tft, padding, bound.h / 2);
			}
			else if (!node->exit_node)
			{
				drawRightArrow(tft, W - padding, line_y - (bound.h / 2));
			}
		}
	}
}

void ConfigListItem::drawLeftArrow(Adafruit_ILI9341* _tft, int x, int y)
{
	tft->drawLine(x, y, x + padding, y - padding, border_color);
	tft->drawLine(x, y, x + padding, y + padding, border_color);
}

void ConfigListItem::drawRightArrow(Adafruit_ILI9341* _tft, int x, int y)
{
	tft->drawLine(x, y, x - padding, y - padding, border_color);
	tft->drawLine(x, y, x - padding, y + padding, border_color);
}



