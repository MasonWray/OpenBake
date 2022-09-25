// 
// 
// 

#include "SolderProfile.h"

SolderProfile::SolderProfile()
{
}

SolderProfile::SolderProfile(String _name, ProfileZone _preheat, ProfileZone _soak, ProfileZone _heat, ProfileZone _flow, ProfileZone _cooldown)
{
	name = _name;
	preheat = _preheat;
	soak = _soak;
	heat = _heat;
	flow = _flow;
	cooldown = _cooldown;
}

SolderProfile::~SolderProfile()
{
}


