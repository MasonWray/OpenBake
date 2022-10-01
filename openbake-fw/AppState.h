// AppState.h

#ifndef _APPSTATE_h
#define _APPSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "SolderProfile.h"

class AppState
{
public:
	AppState();
	~AppState();

	// Settings
	int room_temp = 20;
	int max_temp = 300;

	// Solder Profile
	bool profile_selected;
	SolderProfile current_profile;

	// Run Cycle
	bool running;
	long last_start;
	void startCycle();
	void stopCycle();
};

#endif

