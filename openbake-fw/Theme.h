// Theme.h

#ifndef _THEME_h
#define _THEME_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Theme
{
	static uint16_t border_color = 0xFFFF;
	static uint16_t bg_accent = 0x4208;

	static uint16_t radius = 8;

	static uint8_t padding = 10;
}

#endif

