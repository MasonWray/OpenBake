// 
// 
// 

#include "MainView.h"

using namespace Theme;
using namespace ViewUtils;

MainView::MainView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc, AppState* _state)
{
	type = ViewType::MAIN_VIEW;
	next_view = ViewType::MAIN_VIEW;
	display_width = width;
	display_height = height;
	tft = _tft;
	ts = _ts;
	tc = _tc;
	state = _state;

	timer = millis();
	/*start_pressed = false;
	config_pressed = false;
	start_gap = 0;
	config_gap = 0;*/

	initialize();
}

MainView::~MainView()
{
}

void MainView::initialize()
{
	// Clear Display
	tft->fillScreen(background_color);

	// Draw Temp Chart

	temp_chart = TempChart({ padding, padding, (uint16_t)(display_width - (padding * 2)), chart_height }, state, tft, ts);

	// Draw stats
	tft->setCursor(padding, (padding * 4) + chart_height);
	tft->print("Profile :");
	if (state->profile_selected)
	{
		tft->getTextBounds(state->current_profile.name, tft->getCursorX(), tft->getCursorY(), &profile_box.x, &profile_box.y, &profile_box.w, &profile_box.h);
		tft->printf(state->current_profile.name.c_str());
		tft->println();
	}
	else
	{
		tft->getTextBounds("NONE\n", tft->getCursorX(), tft->getCursorY(), &profile_box.x, &profile_box.y, &profile_box.w, &profile_box.h);
		tft->printf("NONE\n");
	}

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
	start = Button("START", { (int16_t)padding , (int16_t)button_y, (uint16_t)button_width, (uint16_t)button_height }, tft, ts);

	// Draw Config Button
	config = Button("CONFIG", { (int16_t)(button_width + (padding * 2)) , (int16_t)button_y, (uint16_t)button_width, (uint16_t)button_height }, tft, ts);
}

void MainView::update()
{
	// Update Temp Chart
	temp_chart.update(temp);

	// Draw Start/Stop Button
	if (start.update())
	{
		state->startCycle();
	}

	// Draw Config Button
	if (config.update())
	{
		next_view = ViewType::CONFIG_VIEW;
	}

	// Update temperature
	if (millis() - timer > TEMP_UPDATE)
	{
		timer = millis();
		temp = tc->readFahrenheit();
		tft->fillRect(temp_box.x - 1, temp_box.y - 1, temp_box.w + 2, temp_box.h + 2, background_color);
		tft->setCursor(temp_box.x, temp_box.y + temp_box.h - 1);
		char t_buffer[16];
		char s_buffer[16];
		ViewUtils::formatf(temp, 6, 2, t_buffer);
		sprintf(s_buffer, "%s %c", t_buffer, 'F');
		tft->print(s_buffer);
	}
}
