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

	timer = millis();
}

TempController::~TempController()
{
}

void TempController::update()
{
	if (millis() - timer > TEMP_UPDATE)
	{
		timer = millis();
	}
}

int TempController::getTargetTemp()
{

}

int TempController::getActualTemp()
{

}

