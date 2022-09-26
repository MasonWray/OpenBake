// MainView.h

#ifndef _MAINVIEW_h
#define _MAINVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "AppState.h"
#include "View.h"
#include "Theme.h"
#include "ViewUtils.h"
#include "TempChart.h"
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <Adafruit_MAX31855.h>

#define TEMP_UPDATE 1000

class MainView : public View
{
public:
	MainView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc, AppState* _state);
	~MainView();
	void update();
	void initialize();
	bool renderStartButton(bool force);
	bool renderConfigButton(bool force);

private:
	int timer;
	TempChart temp_chart;
	float temp;
	ViewUtils::BoundingBox start_box;
	ViewUtils::BoundingBox config_box;
	ViewUtils::BoundingBox profile_box;
	ViewUtils::BoundingBox time_box;
	ViewUtils::BoundingBox temp_box;
	bool start_pressed;
	bool config_pressed;
	int start_gap;
	int config_gap;
};

#endif

