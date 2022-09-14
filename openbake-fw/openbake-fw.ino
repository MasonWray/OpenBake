/*
 Name:		openbake_fw.ino
 Created:	9/13/2022 7:27:36 PM
 Author:	Mason Wray
*/

#include <Adafruit_DotStar.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

enum ViewState
{
	SPLASH,
	HOME,
	PROFILE,
};

ViewState view;
Adafruit_DotStar* ds;
Adafruit_ILI9341* tft;

void setup() {
	// Initialize view state
	view = SPLASH;

	// Initialize RGB LED
	ds = new Adafruit_DotStar(1, 41, 40, DOTSTAR_BGR);
	ds->begin();
	ds->setBrightness(1);
	ds->setPixelColor(0, ds->gamma32(ds->Color(255, 255, 255)));
	ds->show();

	// Initialize TFT display
	tft = new Adafruit_ILI9341(TFT_CS, TFT_DC);
	tft->begin();
	tft->fillScreen(ILI9341_BLACK);

	// Initialize touch film driver

	// Initialize thermocouple driver

}

void loop() {

}
