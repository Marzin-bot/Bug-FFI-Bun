#ifndef PLANE_H
# define PLANE_H

# include <stdbool.h>
# include "vector3.h"

typedef struct {
    Vector3 *normal;
    float d;
} Plane;

Plane *plane_new(Vector3 *normal, float d);

void plane_free(Plane *plane);

Vector3 *plane_get_normal(const Plane *plane);

void plane_set_normal(Plane *plane, Vector3 *new_normal);

float plane_get_d(const Plane *plane);

void plane_set_d(Plane *plane, const float value);

float plane_get_point_depth(const Plane *plane, const Vector3 *point);

bool plane_is_point_over(const Plane *plane, const Vector3 *point);

#endif
