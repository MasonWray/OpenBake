// 
// 
// 

#include "ProfileView.h"

using namespace Theme;

ProfileView::ProfileView(int width, int height, Adafruit_ILI9341* _tft, TouchScreen* _ts, AppState* _state)
{
	type = ViewType::PROFILE_VIEW;
	next_view = ViewType::PROFILE_VIEW;
	display_width = width;
	display_height = height;
	tft = _tft;
	ts = _ts;
	state = _state;

	initialize();
}

ProfileView::~ProfileView()
{
}

void ProfileView::initialize()
{
	tft->fillScreen(background_color);
}

void ProfileView::update()
{

}


