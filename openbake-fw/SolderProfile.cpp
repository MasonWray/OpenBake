// 
// 
// 

#include "SolderProfile.h"

SolderProfile::SolderProfile()
{
}

SolderProfile::SolderProfile(String _name, String _guid, ProfileZone _preheat, ProfileZone _soak, ProfileZone _heat, ProfileZone _flow, ProfileZone _cooldown)
{
	name = _name;
	guid = _guid;
	preheat = _preheat;
	soak = _soak;
	heat = _heat;
	flow = _flow;
	cooldown = _cooldown;
}

SolderProfile::~SolderProfile()
{
}

int SolderProfile::getTotalDuration()
{
	return preheat.duration + soak.duration + heat.duration + flow.duration + cooldown.duration;
}

