#ifndef UTILS_H
# define UTILS_H

float rad_to_deg(const float deg);

float deg_to_rad(const float rad);

float step(const float min, const float max, const float x);

float lerp(const float a, const float b, const float weight);

float clamp(const float value, const float min, const float max);

#endif