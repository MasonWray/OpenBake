// TempChart.h

#ifndef _TEMPCHART_h
#define _TEMPCHART_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Theme.h"
#include "AppState.h"
#include "ViewUtils.h"
#include "SolderProfile.h"
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

class TempChart
{
public:
	TempChart();
	TempChart(ViewUtils::BoundingBox _bound, AppState* _state, Adafruit_ILI9341* _tft, TouchScreen* _ts);
	~TempChart();

	void initialize();
	void update(int secs, float temp);

private:
	Adafruit_ILI9341* tft;
	TouchScreen* ts;
	ViewUtils::BoundingBox bound;
	AppState* state;
	String last_guid;

	int last_time;
	int last_temp;

	int tempDV(int temp);
	int timeDV(int ms);

	bool isWithinBounds(int x0, int y0, int x1, int y1);
};

#endif

