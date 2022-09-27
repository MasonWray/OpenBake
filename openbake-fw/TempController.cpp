// 
// 
// 

#include "TempController.h"

TempController::TempController(int control_pin, Adafruit_MAX31855* _tc, AppState* _state)
{
	pin = control_pin;
	tc = _tc;
	state = _state;

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	heating = true;

	timer = millis();
}

TempController::~TempController()
{
}

void TempController::update()
{
	if (millis() - timer > TEMP_UPDATE)
	{
		if (state->running && state->profile_selected)
		{
			if (getActualTemp() < getTargetTemp())
			{
				heat();
			}
			else
			{
				cool();
			}
		}
		else
		{

		}
		timer = millis();
	}
}

int TempController::getTargetTemp()
{
	if (state->profile_selected && state->running)
	{

	}
	else
	{
		return 0;
	}
}



int TempController::getActualTemp()
{
	return tc->readCelsius();
}

void TempController::heat()
{
	if (!heating)
	{
		digitalWrite(pin, HIGH);
		heating = true;
	}
}

void TempController::cool()
{
	if (heating)
	{
		digitalWrite(pin, LOW);
		heating = false;
	}
}

