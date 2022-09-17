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
	start_pressed = false;
	config_pressed = false;
	start_gap = 0;
	config_gap = 0;

	initialize();
}

Display::MainView::~MainView()
{
}

void Display::MainView::update()
{
	// Draw Start/Stop Button
	renderStartButton(false);

	// Draw Settings Button
	renderConfigButton(false);

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

	start_box.x = padding;
	start_box.y = button_y;
	start_box.w = button_width;
	start_box.h = button_height;

	config_box.x = button_width + (padding * 2);
	config_box.y = button_y;
	config_box.w = button_width;
	config_box.h = button_height;

	// Draw Start/Stop Button
	renderStartButton(true);

	// Draw Settings Button
	renderConfigButton(true);
}

void Display::MainView::renderStartButton(bool force)
{
	bool rerender = force;
	TSPoint* p = Utils::lerp(ts->getPoint());

	if (p->z > ts->pressureThreshhold)
	{
		if (p->x >= start_box.x && p->x <= start_box.x + start_box.w && p->y >= start_box.y && p->y <= start_box.y + start_box.h)
		{
			rerender = start_pressed ? rerender : true;
			start_pressed = true;
			start_gap = 0;
		}
	}
	else
	{
		if (start_pressed)
		{
			start_gap++;
		}

		if (start_gap > 8 && start_pressed) {
			rerender = true;
			start_pressed = false;
		}
	}

	delete p;
	if (rerender)
	{
		if (start_pressed) { tft->fillRoundRect(start_box.x, start_box.y, start_box.w, start_box.h, radius, bg_selected); }
		else { tft->fillRoundRect(start_box.x, start_box.y, start_box.w, start_box.h, radius, bg_accent); }

		tft->drawRoundRect(start_box.x, start_box.y, start_box.w, start_box.h, radius, border_color);
		tft->setCursor(start_box.x + 24, start_box.y + 24);
		tft->print("START");
	}
}

void Display::MainView::renderConfigButton(bool force)
{
	bool rerender = force;
	TSPoint* p = Utils::lerp(ts->getPoint());

	if (p->z > ts->pressureThreshhold)
	{
		if (p->x >= config_box.x && p->x <= config_box.x + config_box.w && p->y >= config_box.y && p->y <= config_box.y + config_box.h)
		{
			rerender = config_pressed ? rerender : true;
			config_pressed = true;
			config_gap = 0;
		}
	}
	else
	{
		if (config_pressed)
		{
			config_gap++;
		}

		if (config_gap > 8 && config_pressed) {
			rerender = true;
			config_pressed = false;
		}
	}

	delete p;

	if (rerender)
	{
		if (config_pressed) { tft->fillRoundRect(config_box.x, config_box.y, config_box.w, config_box.h, radius, bg_selected); }
		else { tft->fillRoundRect(config_box.x, config_box.y, config_box.w, config_box.h, radius, bg_accent); }

		tft->drawRoundRect(config_box.x, config_box.y, config_box.w, config_box.h, radius, border_color);
		tft->setCursor(config_box.x + 20, config_box.y + 24);
		tft->print("CONFIG");
	}
}


