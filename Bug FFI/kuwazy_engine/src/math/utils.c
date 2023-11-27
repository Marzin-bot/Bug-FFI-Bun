#include <stdlib.h>
#include <math.h>
#include "utils.h"

float rad_to_deg(const float deg){
	return deg * (M_PI / 180);
}

float deg_to_rad(const float rad){
	return rad * (180 / M_PI);
}

float step(const float min, const float max, const float x){
	const float difference = max - min;
	return (x - difference) / difference;
}

float lerp(const float a, const float b, const float weight){
	return a + (b - a) * weight;
}

float clamp(const float value, const float value_min, const float value_max){
	return fmax(fmin(value, value_max), value_min);
}