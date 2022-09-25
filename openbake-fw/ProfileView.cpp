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
	using namespace Theme;
	using namespace ViewUtils;

	tft->fillScreen(background_color);

	BoundingBox b1; b1.x = padding; b1.y = padding; b1.w = display_width - (padding * 2); b1.h = button_height;
	Sn63_Pb37 = Button("Sn63/Pb37", b1, tft, ts);

	BoundingBox b2; b2.x = padding; b2.y = b1.y + b1.h + padding; b2.w = display_width - (padding * 2); b2.h = button_height;
	SAC305 = Button("SAC305", b2, tft, ts);

	BoundingBox bc; bc.x = padding; bc.y = display_height - padding - button_height; bc.w = display_width - (padding * 2); bc.h = button_height;
	cancel = Button("Cancel", bc, tft, ts);
}

void ProfileView::update()
{
	if (Sn63_Pb37.update())
	{
		state->current_profile = SolderProfile("Sn63/Pb37", { 150, 60 }, { 165, 120 }, { 230, 30 }, { 230, 20 }, { 70, 60 });
		state->profile_selected = true;
		next_view = View::MAIN_VIEW;
	}

	if (SAC305.update())
	{
		state->current_profile = SolderProfile("SAC305", { 150, 60 }, { 180, 120 }, { 250, 30 }, { 250, 15 }, { 70, 60 });
		state->profile_selected = true;
		next_view = View::MAIN_VIEW;
	}

	if (cancel.update())
	{
		next_view = View::MAIN_VIEW;
	}
}


