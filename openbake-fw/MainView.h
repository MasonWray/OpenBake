// MainView.h

#ifndef _MAINVIEW_h
#define _MAINVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "View.h"

namespace Display
{
	class MainView : public View
	{
	public:
		MainView();
		~MainView();
		void update();

	private:
	};
}

#endif

