// 
// 
// 

#include "AppState.h"

AppState::AppState()
{
	profile_selected = false;
	running = false;
}

AppState::~AppState()
{
}

void AppState::startCycle()
{
	last_start = millis();
	running = true;
}

void AppState::stopCycle()
{
	running = false;
}