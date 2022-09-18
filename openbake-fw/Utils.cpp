// 
// 
// 

#include "Utils.h"

char* Utils::formatf(double val, signed char width, unsigned char prec, char* sout)
{
	int whole = floor(val);
	float part = val < 0 ? val + ceil(val) : val - whole;
	for (int i = 0; i < prec; i++) { part *= 10; }
	int decimal = round(part);
	sprintf(sout, "%d.%d", whole, decimal);
	return sout;
}

TSPoint* Utils::lerp(TSPoint p)
{
	int x = ((p.x - MIN_X) / (float)(MAX_X - MIN_X)) * W;
	int y = ((p.y - MIN_Y) / (float)(MAX_Y - MIN_Y)) * H;
	TSPoint* r = new TSPoint(x, y, p.z);
	return r;
}

void Utils::updateCurrentView(Display::ViewType new_view, Display::View* cur_view)
{

}
