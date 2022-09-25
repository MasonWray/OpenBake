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
	using namespace ViewUtils;

	tft->fillScreen(background_color);
	BoundingBox t; t.x = 20; t.y = 40; t.w = 100; t.h = 40;
	test = Button("Test", t, tft, ts);
}

void ProfileView::update()
{
	test.update();
}


