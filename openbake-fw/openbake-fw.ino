/*
 Name:		openbake_fw.ino
 Created:	9/13/2022 7:27:36 PM
 Author:	Mason Wray
*/

#include <Adafruit_DotStar.h>

Adafruit_DotStar* ds;

void setup() {
	ds = new Adafruit_DotStar(1, 41, 40, DOTSTAR_BGR);
	ds->begin();
	ds->setBrightness(1);
	ds->setPixelColor(0, ds->gamma32(ds->Color(255, 255, 255)));
	ds->show();
}

void loop() {

}
