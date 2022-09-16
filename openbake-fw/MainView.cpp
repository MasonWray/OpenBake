// 
// 
// 

#include "MainView.h"

using namespace Theme;

Display::MainView::MainView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc)
{
	running = false;
	display_width = width;
	display_height = height;
	tft = _tft;
	ts = _ts;
	tc = _tc;

	initialize();
}

Display::MainView::~MainView()
{
}

void Display::MainView::update()
{
}

void Display::MainView::initialize()
{
	// Draw Temp Chart
	tft->fillRoundRect(padding, padding, display_width - (2 * padding), chart_height, radius, bg_accent);
	tft->drawRoundRect(padding, padding, display_width - (2 * padding), chart_height, radius, border_color);

	// Draw stats
	tft->setFont(&FreeMono9pt7b);

	tft->setCursor(padding, (padding * 4) + chart_height);
	tft->printf("Profile: NONE\n");

	tft->setCursor(padding, tft->getCursorY() + padding);
	tft->printf("Time   : 0:00\n");

	tft->setCursor(padding, tft->getCursorY() + padding);
	tft->printf("Temp   : -- C\n");

	//Calculate Button Sizing
	int button_width = (display_width - (padding * 3)) / 2;
	int button_y = display_height - padding - button_height;
	int b1_x = padding;
	int b2_x = button_width + (padding * 2);

	// Draw Start/Stop Button
	tft->drawRoundRect(b1_x, button_y, button_width, button_height, radius, border_color);
	tft->setCursor(b1_x + 24, button_y + 24);
	tft->print("START");

	// Draw Settings Button
	tft->drawRoundRect(b2_x, button_y, button_width, button_height, radius, border_color);
	tft->setCursor(b2_x + 20, button_y + 24);
	tft->print("CONFIG");

}


