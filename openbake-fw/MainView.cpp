// 
// 
// 

#include "MainView.h"

using namespace Theme;
using namespace Utils;

Display::MainView::MainView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc)
{
	timer = millis();
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
	// Update temperature
	if (millis() - timer > TEMP_UPDATE)
	{
		timer = millis();
		float temp = tc->readFahrenheit();
		tft->setFont(&FreeMono9pt7b);
		tft->fillRect(temp_box.x - 1, temp_box.y - 1, temp_box.w + 2, temp_box.h + 2, background_color);
		tft->setCursor(temp_box.x, temp_box.y + temp_box.h - 1);
		char t_buffer[16];
		char s_buffer[16];
		Utils::formatf(temp, 6, 2, t_buffer);
		sprintf(s_buffer, "%s %c", t_buffer, 'F');
		tft->print(s_buffer);
	}
}

void Display::MainView::initialize()
{
	// Draw Temp Chart
	tft->fillRoundRect(padding, padding, display_width - (2 * padding), chart_height, radius, bg_accent);
	tft->drawRoundRect(padding, padding, display_width - (2 * padding), chart_height, radius, border_color);

	// Draw stats
	tft->setFont(&FreeMono9pt7b);

	tft->setCursor(padding, (padding * 4) + chart_height);
	tft->print("Profile :");
	tft->getTextBounds("NONE\n", tft->getCursorX(), tft->getCursorY(), &profile_box.x, &profile_box.y, &profile_box.w, &profile_box.h);
	tft->printf("NONE\n");

	tft->setCursor(padding, tft->getCursorY() + padding);
	tft->print("Time    :");
	tft->getTextBounds("0:00\n", tft->getCursorX(), tft->getCursorY(), &time_box.x, &time_box.y, &time_box.w, &time_box.h);
	tft->printf("0:00\n");

	tft->setCursor(padding, tft->getCursorY() + padding);
	tft->print("Temp    :");
	tft->getTextBounds("---.-- F\n", tft->getCursorX(), tft->getCursorY(), &temp_box.x, &temp_box.y, &temp_box.w, &temp_box.h);
	tft->printf("---.-- F\n");

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


