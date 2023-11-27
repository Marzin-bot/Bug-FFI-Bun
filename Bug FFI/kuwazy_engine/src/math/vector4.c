#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "vector4.h"
#include "utils.h"

Vector4 *vector4_new(const float x, const float y, const float z, const float w){
    Vector4 *vec4 = (Vector4 *)malloc(sizeof(Vector4));
    if (vec4){
        vec4->x = x;
        vec4->y = y;
        vec4->z = z;
        vec4->w = w;
    }
    return vec4;
}

void vector4_free(Vector4 *vector4){
    free(vector4);
}

Vector4 *vector4_clone(const Vector4 *vector4){
    return vector4_new(vector4->x, vector4->y, vector4->z, vector4->w);
}

void vector4_copy(Vector4 *a, const Vector4 *b){
    vector4_set(a, b->x, b->y, b->z, b->w);
}

void vector4_set(Vector4 *vector4, const float x, const float y, const float z, const float w){
    vector4->x = x;
    vector4->y = y;
    vector4->z = z;
    vector4->z = w;
}

float vector4_get_x(const Vector4 *vector4){
    return vector4->x;
}
void vector4_set_x(Vector4 *vector4, const float value){
    vector4->x = value;
}

float vector4_get_y(const Vector4 *vector4){
    return vector4->y;
}
void vector4_set_y(Vector4 *vector4, const float value){
    vector4->y = value;
}

float vector4_get_z(const Vector4 *vector4){
    return vector4->z;
}
void vector4_set_z(Vector4 *vector4, const float value){
    vector4->z = value;
}

float vector4_get_w(const Vector4 *vector4){
    return vector4->w;
}
void vector4_set_w(Vector4 *vector4, const float value){
    vector4->w = value;
}

void vector4_add(Vector4 *a, const Vector4 *b){
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
    a->w += b->w;
}

void vector4_subtract(Vector4 *a, const Vector4 *b){
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
    a->w -= b->w;
}

void vector4_multiply(Vector4 *a, const Vector4 *b){
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
    a->w *= b->w;
}

void vector4_divide(Vector4 *a, const Vector4 *b){
    a->x /= b->x;
    a->y /= b->y;
    a->z /= b->z;
    a->w /= b->w;
}

void vector4_modulus(Vector4 *a, const Vector4 *b){
    a->x = fmod(a->x, b->x);
    a->y = fmod(a->y, b->y);
    a->z = fmod(a->z, b->z);
    a->w = fmod(a->w, b->w);
}

void vector4_add_scalar(Vector4 *vector4, const float scalar){
    vector4->x += scalar;
    vector4->y += scalar;
    vector4->z += scalar;
    vector4->w += scalar;
}

void vector4_multiply_scalar(Vector4 *vector4, const float scalar){
    vector4->x *= scalar;
    vector4->y *= scalar;
    vector4->z *= scalar;
    vector4->w *= scalar;
}

void vector4_divide_scalar(Vector4 *vector4, const float scalar){
    vector4->x /= scalar;
    vector4->y /= scalar;
    vector4->z /= scalar;
    vector4->w /= scalar;
}

void vector4_inverse(Vector4 *vector4){
    vector4->x = 1 / vector4->x;
    vector4->y = 1 / vector4->y;
    vector4->z = 1 / vector4->z;
    vector4->w = 1 / vector4->w;
}

float vector4_dot(const Vector4 *a, const Vector4 *b){
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

bool vector4_is_equal(const Vector4 *a, const Vector4 *b){
    return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;
}

void vector4_linear_interpolate(Vector4 *a, const Vector4 *b, const float weight){
    a->x = lerp(a->x, b->x, weight);
    a->y = lerp(a->y, b->y, weight);
    a->z = lerp(a->z, b->z, weight);
    a->w = lerp(a->w, b->w, weight);
}

float vector4_distance_squared(const Vector4 *a, const Vector4 *b){
    const float x = a->x - b->x;
    const float y = a->y - b->y;
    const float z = a->z - b->z;
    const float w = a->w - b->w;
    
    return x * x + y * y + z * z + w * w;
}

float vector4_distance(const Vector4 *a, const Vector4 *b){
    return sqrtf(vector4_distance_squared(a, b));
}

float vector4_length_squared(const Vector4 *a){
    return vector4_dot(a, a);
}

float vector4_length(const Vector4 *a){
    return sqrtf(vector4_length_squared(a));
}

void vector4_direction(Vector4 *a, const Vector4 *b){
    vector4_set(
        a,
        b->x - a->x,
        b->y - a->y,
        b->z - a->z,
        b->w - a->w
    );
    vector4_normalize(a);
}

void vector4_normalize(Vector4 *vector4){
    if (!(vector4->x || vector4->y || vector4->z)){
        vector4_set(vector4, 0, 0, 0, 0);
    }

    const float length = vector4_length(vector4);
    vector4_divide_scalar(vector4, length);
}