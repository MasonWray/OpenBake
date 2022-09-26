// Theme.h

#ifndef _THEME_h
#define _THEME_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_ILI9341.h>

// Config View
#define ITEMS_PER_PAGE 7

namespace Theme
{
	// Colors
	static uint16_t border_color = 0xFFFF;
	static uint16_t background_color = 0x0000;
	static uint16_t bg_accent = 0x18E3;
	static uint16_t bg_selected = 0x7BCF;
	static uint16_t target_curve_col = 0x1C2A;

	// Layout
	static uint16_t radius = 6;
	static uint8_t padding = 10;
	static uint16_t chart_height = 130;
	static uint16_t button_height = 40;

	// Config List Item
	static int16_t left_offset = padding * 4;
}

#endif

