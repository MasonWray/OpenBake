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
	const float spacing = 0.38;
	uint16_t t_w; uint16_t t_h; int16_t t_x; int16_t t_y;
	String profile_name = state->profile_selected ? state->current_profile.name : "NONE";

	ViewUtils::BoundingBox profile_box = { (int16_t)padding, (int16_t)((padding * 3) + chart_height), (uint16_t)(display_width - (padding * 2)), 0 };
	tft->getTextBounds(profile_name, profile_box.x, profile_box.y, &t_x, &t_y, &t_w, &t_h);
	profile_box.h = t_h;
	ViewUtils::BoundingBox time_box = profile_box;
	time_box.y += padding * 3;
	ViewUtils::BoundingBox temp_box = time_box;
	temp_box.y += padding * 3;

	profile_kv = KeyVal("Profile", profile_name, profile_box, spacing, tft);
	time_kv = KeyVal("Time", "00:00", time_box, spacing, tft);
	temp_kv = KeyVal("Temp", "--.-- C", temp_box, spacing, tft);

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
	if (millis() - timer > TEMP_UPDATE)
	{
		// Update temperature
		timer = millis();
		temp = tc->readCelsius();

		// Update temp KeyVal
		temp_kv.setValue(String(String(temp, 2) + " C"));

		// Update time KeyVal
		if (state->running)
		{
			time_kv.setValue(ViewUtils::mstot(timer - state->last_start));
		}
		else
		{
			time_kv.setValue(ViewUtils::mstot(0));
		}

	}

	// Update Temp 
	temp_chart.update((timer - state->last_start) / 1000, temp);

	// Update KeyVals
	profile_kv.update();
	time_kv.update();
	temp_kv.update();

	// Draw Start/Stop Button
	if (start.update() && state->profile_selected)
	{
		state->startCycle();
	}

	// Draw Config Button
	if (config.update())
	{
		next_view = ViewType::CONFIG_VIEW;
	}
}
