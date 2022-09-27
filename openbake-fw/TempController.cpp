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
			if (getActualTemp() < getTargetTemp((millis() - state->last_start) / 1000))
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

int TempController::getTargetTemp(int secs)
{
	if (state->profile_selected && state->running)
	{
		int zone_start_temp = state->room_temp;
		int zone_end_temp = state->current_profile.preheat.target;
		int zone_start_time = 0;
		int zone_end_time = state->current_profile.preheat.duration;

		// Find current temp zone
		const int num_zones = 5;
		SolderProfile::ProfileZone zones[] = {
			state->current_profile.preheat,
			state->current_profile.soak,
			state->current_profile.heat,
			state->current_profile.flow,
			state->current_profile.cooldown
		};

		for (int i = 0; i < num_zones; i++)
		{
			// Time is in the current zone
			if (secs >= zone_start_time && secs < zone_end_time)
			{
				int temp_range = zone_end_temp - zone_start_temp;
				int zone_duration = zones[i].duration;
				float degs_per_step = (float)temp_range / (float)zone_duration;
				int target = zone_start_temp + (degs_per_step * (secs - zone_start_time));
				Serial.println(target);
				return target;
			}

			// Time is not in the current zone and there re more zones to check
			else if (i + 1 < num_zones)
			{
				zone_start_temp = zone_end_temp;
				zone_end_temp = zones[i + 1].target;
				zone_start_time = zone_end_time;
				zone_end_time = zone_end_time + zones[i + 1].duration;
			}
		}
		return state->room_temp;
	}
	else
	{
		return state->room_temp;
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

