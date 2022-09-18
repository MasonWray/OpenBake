// 
// 
// 

#include "ConfigView.h"

ConfigView::ConfigView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc)
{
	type = ViewType::CONFIG_VIEW;
	next_view = ViewType::CONFIG_VIEW;
	display_width = width;
	display_height = height;
	tft = _tft;
	ts = _ts;
	tc = _tc;

	initialize();
}

ConfigView::~ConfigView()
{
}

void ConfigView::initialize()
{
	tft->fillScreen(ILI9341_BLACK);
}

void ConfigView::update()
{

}


