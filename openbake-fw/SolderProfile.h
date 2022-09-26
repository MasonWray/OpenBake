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
	struct ProfileZone
	{
		int target;
		int duration;
	};

	SolderProfile();
	SolderProfile(String _name, String _guid, ProfileZone _preheat, ProfileZone _soak, ProfileZone _heat, ProfileZone _flow, ProfileZone _cooldown);
	~SolderProfile();
	String name;
	String guid;
	ProfileZone preheat;
	ProfileZone soak;
	ProfileZone heat;
	ProfileZone flow;
	ProfileZone cooldown;

	int getTotalDuration();
};

#endif

