#include <stdlib.h>
#include <stdbool.h>
#include "plane.h"
#include "vector3.h"

Plane *plane_new(Vector3 *normal, float d){
    Plane *plane = (Plane *)malloc(sizeof(Plane));
    if (plane){
        plane->normal = normal;
        plane->d = d;
    }

    return plane;
}

void plane_free(Plane *plane){
    free(plane);
}

Vector3 *plane_get_normal(const Plane *plane){
    return plane->normal;
}
void plane_set_normal(Plane *plane, Vector3 *new_normal){
    plane->normal = new_normal;
}

float plane_get_d(const Plane *plane){
    return plane->d;
}
void plane_set_d(Plane *plane, const float value){
    plane->d = value;
}

float plane_get_point_depth(const Plane *plane, const Vector3 *point){
    return vector3_dot(plane->normal, point) + plane->d;
}

bool plane_is_point_over(const Plane *plane, const Vector3 *point){
    return plane_get_point_depth(plane, point) <= 0;
}