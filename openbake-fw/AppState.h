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
	bool profile_selected;
	SolderProfile current_profile;
};

#endif

