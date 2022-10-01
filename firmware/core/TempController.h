// TempController.h

#ifndef _TEMPCONTROLLER_h
#define _TEMPCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"
#include "AppState.h"
#include "SolderProfile.h"
#include <Adafruit_MAX31855.h>

class TempController
{
public:
	TempController(int control_pin, Adafruit_MAX31855* _tc, AppState* _state);
	~TempController();
	void update();

private:
	Adafruit_MAX31855* tc;
	AppState* state;

	int timer;
	int pin;
	bool heating;

	int getTargetTemp(int secs);
	int getActualTemp();

	void heat();
	void cool();
};

#endif

