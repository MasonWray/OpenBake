// 
// 
// 

#include "ViewUtils.h"

TSPoint* ViewUtils::lerp(TSPoint p)
{
	int x = ((p.x - MIN_X) / (float)(MAX_X - MIN_X)) * W;
	int y = ((p.y - MIN_Y) / (float)(MAX_Y - MIN_Y)) * H;
	TSPoint* r = new TSPoint(x, y, p.z);
	return r;
}

#define MINUTE 60000
#define SECOND 1000

String ViewUtils::mstot(int ms)
{
	int mins = ms / MINUTE;
	int secs = (ms - (mins * MINUTE)) / SECOND;
	String minstr = String(mins).length() >= 2 ? String(mins) : String("0" + String(mins));
	String secstr = String(secs).length() >= 2 ? String(secs) : String("0" + String(secs));
	return String(minstr + ":" + secstr);
}
