// 
// 
// 

#include "TempChart.h"

TempChart::TempChart() {}

TempChart::TempChart(ViewUtils::BoundingBox _bound, AppState* _state, Adafruit_ILI9341* _tft, TouchScreen* _ts)
{
	tft = _tft;
	ts = _ts;
	bound = _bound;
	state = _state;

	initialize();
}

TempChart::~TempChart()
{

}

void TempChart::initialize()
{
	using namespace Theme;

	// Draw Temp Chart
	tft->fillRoundRect(padding, padding, bound.w, bound.h, radius, bg_accent);
	tft->drawRoundRect(padding, padding, bound.w, bound.h, radius, border_color);
}

void TempChart::update(float temp)
{
	using namespace Theme;

	if (!last_guid.equals(state->current_profile.guid))
	{
		last_guid = state->current_profile.guid;

		// Clear Component
		tft->fillRoundRect(padding, padding, bound.w, bound.h, radius, bg_accent);

		// Draw Target Curve
		int start_x = 0;
		int preheat_x = start_x + state->current_profile.preheat.duration;
		int soak_x = preheat_x + state->current_profile.soak.duration;
		int heat_x = soak_x + state->current_profile.heat.duration;
		int flow_x = heat_x + state->current_profile.flow.duration;
		int cooldown_x = flow_x + state->current_profile.cooldown.duration;
		tft->drawLine(timeDV(start_x), tempDV(state->room_temp), timeDV(preheat_x), tempDV(state->current_profile.preheat.target), target_curve_col);
		tft->drawLine(timeDV(preheat_x), tempDV(state->current_profile.preheat.target), timeDV(soak_x), tempDV(state->current_profile.soak.target), target_curve_col);
		tft->drawLine(timeDV(soak_x), tempDV(state->current_profile.soak.target), timeDV(heat_x), tempDV(state->current_profile.heat.target), target_curve_col);
		tft->drawLine(timeDV(heat_x), tempDV(state->current_profile.heat.target), timeDV(flow_x), tempDV(state->current_profile.flow.target), target_curve_col);
		tft->drawLine(timeDV(flow_x), tempDV(state->current_profile.flow.target), timeDV(cooldown_x), tempDV(state->current_profile.cooldown.target), target_curve_col);

		// Draw Border
		tft->drawRoundRect(padding, padding, bound.w, bound.h, radius, border_color);
	}
}

int TempChart::tempDV(int temp)
{
	int min_temp = state->room_temp - 10;
	int temp_range = state->max_temp - min_temp;
	return (bound.y + bound.h) - (((float)temp / (float)temp_range) * (float)bound.h);
}

int TempChart::timeDV(int sec)
{
	int max_time = state->current_profile.getTotalDuration();
	return bound.x + (((float)sec / (float)max_time) * (float)bound.w);
}


