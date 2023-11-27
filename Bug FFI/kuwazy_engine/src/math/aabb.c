#include <stdlib.h>
#include <stdbool.h>
#include "aabb.h"
#include "vector3.h"

AABB *aabb_new(Vector3 *position, Vector3 *size){
    AABB *aabb = (AABB *)malloc(sizeof(AABB));
    if (aabb){
        aabb->position = position;
        aabb->size = size;
    }

    return aabb;
}

void aabb_free(AABB *aabb){
    free(aabb);
}

Vector3 *aabb_get_position(const AABB *aabb){
    return aabb->position;
}

void aabb_set_position(AABB *aabb, Vector3 *new_position){
    aabb->position = new_position;
}

Vector3 *aabb_get_size(const AABB *aabb){
    return aabb->size;
}

void aabb_set_size(AABB *aabb, Vector3 *new_size){
    aabb->size = new_size;
}

bool aabb_intersects(const AABB *a, const AABB *b){
    if (a->position->x >= (b->position->x + b->size->x)){
		return false;
	}
	if ((a->position->x + a->size->x) <= b->position->x){
		return false;
	}
	if (a->position->y >= (b->position->y + b->size->y)){
		return false;
	}
	if ((a->position->y + a->size->y) <= b->position->y){
		return false;
	}
	if (a->position->z >= (b->position->z + b->size->z)){
		return false;
	}
	if ((a->position->z + a->size->z) <= b->position->z){
		return false;
	}

    return true;
}

bool aabb_encloses(const AABB *a, const AABB *b){
    return a->position->x <= b->position->x
    && a->position->x + a->size->x >= b->position->x + b->size->x
    && a->position->y <= b->position->y
    && a->position->y + a->size->y >= b->position->y + b->size->y
    && a->position->z <= b->position->z
    && a->position->z + a->size->z >= b->position->z + b->size->z;
}

void aabb_get_center(const AABB *aabb, Vector3 *center){
    vector3_set(
        center,
        aabb->position->x + (aabb->size->x / 2),
        aabb->position->y + (aabb->size->y / 2),
        aabb->position->z + (aabb->size->z / 2)
    );
}

void aabb_grow(AABB *aabb, const float by){
    vector3_add_scalar(aabb->position, -by);
    vector3_add_scalar(aabb->size, by * 2);
}

void aabb_merge(AABB *a, const AABB *b){
    float a_end_x = a->position->x + a->size->x;
    float a_end_y = a->position->y + a->size->y;
    float a_end_z = a->position->z + a->size->z;

    const float b_end_x = b->position->x + b->size->x;
    const float b_end_y = b->position->y + b->size->y;
    const float b_end_z = b->position->z + b->size->z;

    if (b->position->x < a->position->x){
        a->position->x = b->position->x;
    }
    if (b->position->y < a->position->y){
        a->position->y = b->position->y;
    }
    if (b->position->z < a->position->z){
        a->position->z = b->position->z;
    }

    if (b_end_x > a_end_x){
        a_end_x = b_end_x;
    }
    if (b_end_y > a_end_y){
        a_end_y = b_end_y;
    }
    if (b_end_z > a_end_z){
        a_end_z = b_end_z;
    }

    a->size->x = a_end_x - a->position->x;
    a->size->y = a_end_y - a->position->y;
    a->size->z = a_end_z - a->position->z;
}

bool aabb_is_equal(const AABB *a, const AABB *b){
    return vector3_is_equal(a->position, b->position) && vector3_is_equal(a->size, b->size);
}

float aabb_get_volume(const AABB *aabb){
    return aabb->size->x * aabb->size->y * aabb->size->z;
}

Vector3 *aabb_get_endpoint(const AABB *aabb, const uint8_t index){
    switch (index){
        case 0:
            return vector3_new(aabb->position->x, aabb->position->y, aabb->position->z);
        case 1:
            return vector3_new(aabb->position->x, aabb->position->y, aabb->position->z + aabb->size->z);
        case 2:
            return vector3_new(aabb->position->x, aabb->position->y + aabb->size->y, aabb->position->z);
        case 3:
            return vector3_new(aabb->position->x, aabb->position->y + aabb->size->y, aabb->position->z + aabb->size->z);
        case 4:
            return vector3_new(aabb->position->x + aabb->size->x, aabb->position->y, aabb->position->z);
        case 5:
            return vector3_new(aabb->position->x + aabb->size->x, aabb->position->y, aabb->position->z + aabb->size->z);
        case 6:
            return vector3_new(aabb->position->x + aabb->size->x, aabb->position->y + aabb->size->y, aabb->position->z);
        case 7:
            return vector3_new(aabb->position->x + aabb->size->x, aabb->position->y + aabb->size->y, aabb->position->z + aabb->size->z);
    }

    return NULL;
}