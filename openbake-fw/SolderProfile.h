// SolderProfile.h

#ifndef _SOLDERPROFILE_h
#define _SOLDERPROFILE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SolderProfile
{
public:
	SolderProfile();
	SolderProfile(float _preheat, int _soak, float _heat, int _flow, float _cooldown);
	~SolderProfile();
	float preheat;
	int soak;
	float heat;
	int flow;
	float cooldown;
};

#endif

