#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "vector3.h"
#include "utils.h"

Vector3 *vector3_new(const float x, const float y, const float z){
    Vector3 *vec3 = (Vector3 *)malloc(sizeof(Vector3));
    if (vec3){
        vector3_set(vec3, x, y, z);
    }
    return vec3;
}

void vector3_free(Vector3 *vector3){
    free(vector3);
}

Vector3 *vector3_clone(const Vector3 *vector3){
    return vector3_new(vector3->x, vector3->y, vector3->z);
}

void vector3_copy(Vector3 *a, const Vector3 *b){
    vector3_set(a, b->x, b->y, b->z);
}

void vector3_set(Vector3 *vector3, const float x, const float y, const float z){
    vector3->x = x;
    vector3->y = y;
    vector3->z = z;
}

float vector3_get_x(const Vector3 *vector3){
    return vector3->x;
}
void vector3_set_x(Vector3 *vector3, const float value){
    vector3->x = value;
}

float vector3_get_y(const Vector3 *vector3){
    return vector3->y;
}
void vector3_set_y(Vector3 *vector3, const float value){
    vector3->y = value;
}

float vector3_get_z(const Vector3 *vector3){
    return vector3->z;
}
void vector3_set_z(Vector3 *vector3, const float value){
    vector3->z = value;
}

void vector3_add(Vector3 *a, const Vector3 *b){
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

void vector3_subtract(Vector3 *a, const Vector3 *b){
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
}

void vector3_multiply(Vector3 *a, const Vector3 *b){
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
}

void vector3_divide(Vector3 *a, const Vector3 *b){
    a->x /= b->x;
    a->y /= b->y;
    a->z /= b->z;
}

void vector3_modulus(Vector3 *a, const Vector3 *b){
    a->x = fmod(a->x, b->x);
    a->y = fmod(a->y, b->y);
    a->z = fmod(a->z, b->z);
}

void vector3_add_scalar(Vector3 *vector3, const float scalar){
    vector3->x += scalar;
    vector3->y += scalar;
    vector3->z += scalar;
}

void vector3_multiply_scalar(Vector3 *vector3, const float scalar){
    vector3->x *= scalar;
    vector3->y *= scalar;
    vector3->z *= scalar;
}

void vector3_divide_scalar(Vector3 *vector3, const float scalar){
    if (scalar){
        vector3->x /= scalar;
        vector3->y /= scalar;
        vector3->z /= scalar;
    }
}

void vector3_inverse(Vector3 *vector3){
    if (vector3->x && vector3->y && vector3->z){
        vector3->x = 1 / vector3->x;
        vector3->y = 1 / vector3->y;
        vector3->z = 1 / vector3->z;
    }
}

void vector3_cross(Vector3 *a, const Vector3 *b){
    const float x = a->y * b->z - a->z * b->y;
    const float y = a->z * b->x - a->x * b->z;
    const float z = a->x * b->y - a->y * b->z;
    vector3_set(a, x, y, z);
}

float vector3_dot(const Vector3 *a, const Vector3 *b){
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

bool vector3_is_equal(const Vector3 *a, const Vector3 *b){
    return a->x == b->x && a->y == b->y && a->z == b->z;
}

void vector3_linear_interpolate(Vector3 *a, const Vector3 *b, const float weight){
    a->x = lerp(a->x, b->x, weight);
    a->y = lerp(a->y, b->y, weight);
    a->z = lerp(a->z, b->z, weight);
}

float vector3_distance_squared(const Vector3 *a, const Vector3 *b){
    const float x = a->x - b->x;
    const float y = a->y - b->y;
    const float z = a->z - b->z;

    return x * x + y * y + z * z;
}

float vector3_distance(const Vector3 *a, const Vector3 *b){
    return sqrtf(vector3_distance_squared(a, b));
}

float vector3_length_squared(const Vector3 *a){
    return vector3_dot(a, a);
}

float vector3_length(const Vector3 *a){
    return sqrtf(vector3_length_squared(a));
}

void vector3_direction(Vector3 *a, const Vector3 *b){
    vector3_set(
        a,
        b->x - a->x,
        b->y - a->y,
        b->z - a->z
    );
    vector3_normalize(a);
}

void vector3_normalize(Vector3 *vector3){
    if (!(vector3->x || vector3->y || vector3->z)){
        vector3_set(vector3, 0, 0, 0);
    }

    const float length = vector3_length(vector3);
    vector3_divide_scalar(vector3, length);
}

float vector3_angle(const Vector3 *a, const Vector3 *b){
    Vector3 *a_copied = vector3_clone(a);
    vector3_cross(a_copied, b);

    const float result = atan2f(vector3_length(a_copied), vector3_dot(a, b));

    vector3_free(a_copied);

    return result;
}