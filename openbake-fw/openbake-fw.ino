/*
 Name:		openbake_fw.ino
 Created:	9/13/2022 7:27:36 PM
 Author:	Mason Wray
*/

#include "MainView.h"
#include "View.h"
#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <Adafruit_MAX31855.h>

#define TFT_DC 9
#define TFT_CS 10

#define YP A5
#define XM A3
#define YM 12
#define XP 11

#define MAXDO   2
#define MAXCS   7
#define MAXCLK  13

#define MAX_X 820
#define MAX_Y 911
#define MIN_X 230
#define MIN_Y 147

#define W 240
#define H 320

Adafruit_DotStar ds(1, 41, 40, DOTSTAR_BGR);
Adafruit_ILI9341 tft(TFT_CS, TFT_DC);
TouchScreen ts(XP, YP, XM, YM, 300);
Adafruit_MAX31855 tc(MAXCLK, MAXCS, MAXDO);

int minX = 500, minY = 500, maxX = 0, maxY = 0;

float lastTemp = 0;

Display::View* view;

void setup() {
	Serial.begin(9600);
	while (!Serial) delay(1);

	// Initialize RGB LED
	ds.begin();
	ds.setBrightness(1);
	ds.setPixelColor(0, ds.gamma32(ds.Color(255, 255, 255)));
	ds.show();

	// Initialize TFT display
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);

	// Initialize touch film driver

	// Initialize thermocouple driver
	if (!tc.begin()) {
		Serial.println("Thermocouple failed to initialize.");
	}
	Serial.println("Ready.");

	// Initialize view controller
	view = new Display::MainView(W, H, &tft);
}

void loop() {
	/*TSPoint* p = lerp(ts.getPoint());
	if (p->z > ts.pressureThreshhold) {
		tft->drawPixel(p->x, p->y, ILI9341_WHITE);
	}
	delete p;*/

	float temp = tc.readFahrenheit();
	if (lastTemp != temp) {
		lastTemp = temp;
	}

	view->update();
}

TSPoint* lerp(TSPoint p) {
	int x = ((p.x - MIN_X) / (float)(MAX_X - MIN_X)) * W;
	int y = ((p.y - MIN_Y) / (float)(MAX_Y - MIN_Y)) * H;
	TSPoint* r = new TSPoint(x, y, p.z);
	return r;
}