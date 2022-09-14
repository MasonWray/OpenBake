/*
 Name:		openbake_fw.ino
 Created:	9/13/2022 7:27:36 PM
 Author:	Mason Wray
*/

#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

#define TFT_DC 9
#define TFT_CS 10

#define YP A5
#define XM A3
#define YM 12
#define XP 11

#define MAX_X 820
#define MAX_Y 911
#define MIN_X 230
#define MIN_Y 147

#define W 240
#define H 320

Adafruit_DotStar* ds;
Adafruit_ILI9341* tft;
TouchScreen* ts;

int minX = 500, minY = 500, maxX = 0, maxY = 0;

void setup() {
	Serial.begin(9600);

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
	ts = new TouchScreen(XP, YP, XM, YM, 300);

	// Initialize thermocouple driver

}

void loop() {
	TSPoint* p = lerp(ts->getPoint());

	if (p->z > ts->pressureThreshhold) {
		tft->drawPixel(p->x, p->y, ILI9341_WHITE);
	}
	delete p;
}

TSPoint* lerp(TSPoint p) {
	int x = ((p.x - MIN_X) / (float)(MAX_X - MIN_X)) * W;
	int y = ((p.y - MIN_Y) / (float)(MAX_Y - MIN_Y)) * H;
	TSPoint* r = new TSPoint(x, y, p.z);
	return r;
}