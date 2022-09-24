// 
// 
// 

#include "SolderProfile.h"

SolderProfile::SolderProfile()
{
}

SolderProfile::SolderProfile(float _preheat, int _soak, float _heat, int _flow, float _cooldown)
{
	preheat = _preheat;
	soak = _soak;
	heat = _heat;
	flow = _flow;
	cooldown = _cooldown;
}

SolderProfile::~SolderProfile()
{
}


