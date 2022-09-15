// 
// 
// 

#include "MainView.h"

using namespace Theme;

Display::MainView::MainView(int width, int height, Adafruit_ILI9341* _tft)
{
	display_width = width;
	display_height = height;
	tft = _tft;

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
	// Draw Profile
	tft->setTextSize(1);
	tft->setCursor(padding, padding);
	tft->println("Profile: NONE");

	// Draw Temp Chart
	tft->fillRoundRect(padding, (2 * padding) + 10, display_width - (2 * padding), 100, radius, bg_accent);
	tft->drawRoundRect(padding, (2 * padding) + 10, display_width - (2 * padding), 100, radius, border_color);
}
