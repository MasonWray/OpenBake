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

namespace Display
{
	class MainView : public View
	{
	public:
		MainView(int width, int height, Adafruit_ILI9341* _tft);
		~MainView();
		void update();
		void initialize();

	private:
		int display_width;
		int display_height;
		Adafruit_ILI9341* tft;
	};
}

#endif

