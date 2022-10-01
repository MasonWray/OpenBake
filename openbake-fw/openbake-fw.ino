/*
 Name:		openbake_fw.ino
 Created:	9/13/2022 7:27:36 PM
 Author:	Mason Wray
*/

#include "AppState.h"
#include "SplashView.h"
#include "ConfigView.h"
#include "ProfileView.h"
#include "ViewUtils.h"
#include "MainView.h"
#include "View.h"
#include "Config.h"
#include "TempController.h"
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

#define SSR 0

Adafruit_DotStar ds = Adafruit_DotStar(1, 41, 40, DOTSTAR_BGR);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_MAX31855 tc = Adafruit_MAX31855(MAXCLK, MAXCS, MAXDO);

int minX = 500, minY = 500, maxX = 0, maxY = 0;

AppState state = AppState();
View* view;
TempController temp_controller = TempController(SSR, &tc, &state);

void setup() {
	Serial.begin(115200);
	while (!Serial) delay(1);

	// Initialize RGB LED
	ds.begin();
	ds.setBrightness(1);
	ds.setPixelColor(0, ds.gamma32(ds.Color(255, 255, 255)));
	ds.show();

	// Initialize TFT display
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);

	// Initialize thermocouple driver
	if (!tc.begin()) {
		Serial.println("Thermocouple failed to initialize.");
	}
	Serial.println("Ready.");

	// Initialize view controller
	view = new SplashView(W, H, &tft);
}

void loop() {
	temp_controller.update();
	view->update();

	if (view->next_view != view->type)
	{
		switch (view->next_view)
		{
		case View::SPLASH_VIEW:
			delete view;
			view = new SplashView(W, H, &tft);
			break;
		case View::MAIN_VIEW:
			delete view;
			view = new MainView(W, H, &tft, &ts, &tc, &state);
			break;
		case View::CONFIG_VIEW:
			delete view;
			view = new ConfigView(W, H, &tft, &ts, &tc);
			break;
		case View::PROFILE_VIEW:
			delete view;
			view = new ProfileView(W, H, &tft, &ts, &state);
		default:
			break;
		}
	}
}