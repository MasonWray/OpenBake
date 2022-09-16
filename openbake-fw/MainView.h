// MainView.h

#ifndef _MAINVIEW_h
#define _MAINVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "View.h"
#include <Adafruit_ILI9341.h>
#include "Theme.h"
#include <TouchScreen.h>
#include <Adafruit_MAX31855.h>
#include <Fonts/FreeMono9pt7b.h>

namespace Display
{
	class MainView : public View
	{
	public:
		MainView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, Adafruit_MAX31855* _tc);
		~MainView();
		void update();
		void initialize();
		void renderStartButton(int x, int y, int w, int h);
		void renderConfigButton(int x, int y, int w, int h);

	private:
		bool running;
		int display_width;
		int display_height;
		Adafruit_ILI9341* tft;
		TouchScreen* ts;
		Adafruit_MAX31855* tc;
	};
}

#endif

