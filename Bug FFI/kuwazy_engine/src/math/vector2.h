#ifndef VECTOR2_H
# define VECTOR2_H

# include <stdbool.h>

typedef struct Vector2{
    union {
        struct {
            float x;
            float y;
        };
        float buffer[2];
    };
} Vector2;

Vector2 *vector2_new(const float x, const float y);

void vector2_free(Vector2 *vector2);

Vector2 *vector2_clone(const Vector2 *vector2);

void vector2_copy(Vector2 *a, const Vector2 *b);

void vector2_set(Vector2 *vector2, const float x, const float y);

float vector2_get_x(const Vector2 *vector2);
void vector2_set_x(Vector2 *vector2, const float value);

float vector2_get_y(const Vector2 *vector2);
void vector2_set_y(Vector2 *vector2, const float value);

void vector2_add(Vector2 *a, const Vector2 *b);

void vector2_subtract(Vector2 *a, const Vector2 *b);

void vector2_multiply(Vector2 *a, const Vector2 *b);

void vector2_divide(Vector2 *a, const Vector2 *b);

void vector2_modulus(Vector2 *a, const Vector2 *b);

void vector2_add_scalar(Vector2 *vector2, const float scalar);

void vector2_multiply_scalar(Vector2 *vector2, const float scalar);

void vector2_divide_scalar(Vector2 *vector2, const float scalar);

void vector2_inverse(Vector2 *vector2);

float vector2_cross(const Vector2 *a, const Vector2 *b);

float vector2_dot(const Vector2 *a, const Vector2 *b);

bool vector2_is_equal(const Vector2 *a, const Vector2 *b);

void vector2_linear_interpolate(Vector2 *a, const Vector2 *b, const float weight);

float vector2_distance_squared(const Vector2 *a, const Vector2 *b);

float vector2_distance(const Vector2 *a, const Vector2 *b);

float vector2_length_squared(const Vector2 *a);

float vector2_length(const Vector2 *a);

void vector2_direction(Vector2 *a, const Vector2 *b);

void vector2_normalize(Vector2 *vector2);

float vector2_angle(const Vector2 *a, const Vector2 *b);

#endif
