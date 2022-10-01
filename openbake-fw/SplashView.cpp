// 
// 
// 

#include "SplashView.h"

using namespace Theme;

SplashView::SplashView(int width, int height, Adafruit_ILI9341* _tft)
{
	type = ViewType::SPLASH_VIEW;
	next_view = ViewType::SPLASH_VIEW;
	display_width = width;
	display_height = height;
	tft = _tft;
	timer = millis();

	initialize();
}

SplashView::~SplashView()
{

}

void SplashView::initialize()
{
	String heading = "OpenBake";
	String brand = "EMERSON LABS";
	String version = FIRMWARE_VERSION;

	uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;

	tft->fillScreen(bg_default);
	tft->setFont(&FreeMono24pt7b);
	tft->getTextBounds(heading, 0, 0, &t_x, &t_y, &t_w, &t_h);
	tft->setCursor((display_width - t_w) / 2, display_height / 3);
	tft->println(heading);

	tft->setFont(&FreeMono12pt7b);
	tft->getTextBounds(brand, 0, 0, &t_x, &t_y, &t_w, &t_h);
	tft->setCursor((display_width - t_w) / 2, display_height - (display_height / 5));
	tft->println(brand);

	tft->setFont(&FreeMono9pt7b);
	tft->getTextBounds(version, 0, 0, &t_x, &t_y, &t_w, &t_h);
	tft->setCursor((display_width - t_w) / 2, display_height - (display_height / 8));
	tft->println(version);

}

void SplashView::update()
{
	if (millis() - timer > POST_DELAY)
	{
		next_view = ViewType::MAIN_VIEW;
	}
}


