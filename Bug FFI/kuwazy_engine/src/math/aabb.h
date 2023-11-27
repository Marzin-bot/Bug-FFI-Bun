#ifndef AABB_H
# define AABB_H

# include <stdbool.h>
# include <stdint.h>
# include "vector3.h"

typedef struct {
    Vector3 *position;
    Vector3 *size;
} AABB;

AABB *aabb_new(Vector3 *position, Vector3 *size);

void aabb_free(AABB *aabb);

Vector3 *aabb_get_position(const AABB *aabb);

void aabb_set_position(AABB *aabb, Vector3 *new_position);

Vector3 *aabb_get_size(const AABB *aabb);

void aabb_set_size(AABB *aabb, Vector3 *new_size);

bool aabb_intersects(const AABB *a, const AABB *b);

bool aabb_encloses(const AABB *a, const AABB *b);

void aabb_get_center(const AABB *aabb, Vector3 *center);

void aabb_grow(AABB *aabb, const float by);

void aabb_merge(AABB *a, const AABB *b);

bool aabb_is_equal(const AABB *a, const AABB *b);

float aabb_get_volume(const AABB *aabb);

Vector3 *aabb_get_endpoint(const AABB *aabb, const uint8_t index);

#endif
