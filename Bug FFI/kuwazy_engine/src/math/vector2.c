#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "vector2.h"
#include "utils.h"

Vector2 *vector2_new(const float x, const float y){
    Vector2 *vec2 = (Vector2 *)malloc(sizeof(Vector2));
    if (vec2){
        vec2->x = x;
        vec2->y = y;
    }
    return vec2;
}

void vector2_free(Vector2 *vector2){
    free(vector2);
}

Vector2 *vector2_clone(const Vector2 *vector2){
    return vector2_new(vector2->x, vector2->y);
}

void vector2_copy(Vector2 *a, const Vector2 *b){
    vector2_set(a, b->x, b->y);
}

void vector2_set(Vector2 *vector2, const float x, const float y){
    vector2->x = x;
    vector2->y = y;
}

float vector2_get_x(const Vector2 *vector2){
    return vector2->x;
}
void vector2_set_x(Vector2 *vector2, const float value){
    vector2->x = value;
}

float vector2_get_y(const Vector2 *vector2){
    return vector2->y;
}
void vector2_set_y(Vector2 *vector2, const float value){
    vector2->y = value;
}

void vector2_add(Vector2 *a, const Vector2 *b){
    a->x += b->x;
    a->y += b->y;
}

void vector2_subtract(Vector2 *a, const Vector2 *b){
    a->x -= b->x;
    a->y -= b->y;
}

void vector2_multiply(Vector2 *a, const Vector2 *b){
    a->x *= b->x;
    a->y *= b->y;
}

void vector2_divide(Vector2 *a, const Vector2 *b){
    a->x /= b->x;
    a->y /= b->y;
}

void vector2_modulus(Vector2 *a, const Vector2 *b){
    a->x = fmod(a->x, b->x);
    a->y = fmod(a->y, b->y);
}

void vector2_add_scalar(Vector2 *vector2, const float scalar){
    vector2->x += scalar;
    vector2->y += scalar;
}

void vector2_multiply_scalar(Vector2 *vector2, const float scalar){
    vector2->x *= scalar;
    vector2->y *= scalar;
}

void vector2_divide_scalar(Vector2 *vector2, const float scalar){
    vector2->x /= scalar;
    vector2->y /= scalar;
}

void vector2_inverse(Vector2 *vector2){
    vector2->x = 1 / vector2->x;
    vector2->y = 1 / vector2->y;
}

float vector2_cross(const Vector2 *a, const Vector2 *b){
    return a->x * b->y - a->y * b->x;
}

float vector2_dot(const Vector2 *a, const Vector2 *b){
    return a->x * b->x + a->y * b->y;
}

bool vector2_is_equal(const Vector2 *a, const Vector2 *b){
    return a->x == b->x && a->y == b->y;
}

void vector2_linear_interpolate(Vector2 *a, const Vector2 *b, const float weight){
    a->x = lerp(a->x, b->x, weight);
    a->y = lerp(a->y, b->y, weight);
}

float vector2_distance_squared(const Vector2 *a, const Vector2 *b){
    const float x = a->x - b->x;
    const float y = a->y - b->y;

    return x * x + y * y;
}

float vector2_distance(const Vector2 *a, const Vector2 *b){
    return sqrtf(vector2_distance_squared(a, b));
}

float vector2_length_squared(const Vector2 *a){
    return vector2_dot(a, a);
}

float vector2_length(const Vector2 *a){
    return sqrtf(vector2_length_squared(a));
}

void vector2_direction(Vector2 *a, const Vector2 *b){
    vector2_set(
        a,
        b->x - a->x,
        b->y - a->y
    );
    vector2_normalize(a);
}

void vector2_normalize(Vector2 *vector2){
    if (!(vector2->x || vector2->y)){
        vector2_set(vector2, 0, 0);
    }

    const float length = vector2_length(vector2);
    vector2_divide_scalar(vector2, length);
}

float vector2_angle(const Vector2 *a, const Vector2 *b){
    Vector2 *a_copied = vector2_clone(a);
    vector2_cross(a_copied, b);

    const float result = atan2f(vector2_length(a_copied), vector2_dot(a, b));

    vector2_free(a_copied);

    return result;
}