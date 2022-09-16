// 
// 
// 

#include "Utils.h"

char* Utils::formatf(double val, signed char width, unsigned char prec, char* sout) {
	int whole = floor(val);
	float part = val < 0 ? val + ceil(val) : val - whole;
	for (int i = 0; i < prec; i++) { part *= 10; }
	int decimal = round(part);
	sprintf(sout, "%d.%d", whole, decimal);
	return sout;
}

