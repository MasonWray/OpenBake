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
	static uint16_t background_color = 0x0000;
	static uint16_t bg_accent = 0x18E3;

	static uint16_t radius = 8;

	static uint8_t padding = 10;

	static uint16_t chart_height = 130;
	static uint16_t button_height = 40;
}

#endif

