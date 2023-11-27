#ifndef VECTOR4_H
# define VECTOR4_H

# include <stdbool.h>

typedef struct Vector4{
    union { 
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float buffer[4];
    };
} Vector4;

Vector4 *vector4_new(const float x, const float y, const float z, const float w);

void vector4_free(Vector4 *vector4);

Vector4 *vector4_clone(const Vector4 *vector4);

void vector4_copy(Vector4 *a, const Vector4 *b);

void vector4_set(Vector4 *vector4, const float x, const float y, const float z, const float w);

float vector4_get_x(const Vector4 *vector4);
void vector4_set_x(Vector4 *vector4, const float value);

float vector4_get_y(const Vector4 *vector4);
void vector4_set_y(Vector4 *vector4, const float value);

float vector4_get_z(const Vector4 *vector4);
void vector4_set_z(Vector4 *vector4, const float value);

float vector4_get_w(const Vector4 *vector4);
void vector4_set_w(Vector4 *vector4, const float value);

void vector4_add(Vector4 *a, const Vector4 *b);

void vector4_subtract(Vector4 *a, const Vector4 *b);

void vector4_multiply(Vector4 *a, const Vector4 *b);

void vector4_divide(Vector4 *a, const Vector4 *b);

void vector4_modulus(Vector4 *a, const Vector4 *b);

void vector4_add_scalar(Vector4 *vector4, const float scalar);

void vector4_multiply_scalar(Vector4 *vector4, const float scalar);

void vector4_divide_scalar(Vector4 *vector4, const float scalar);

void vector4_inverse(Vector4 *vector4);

float vector4_dot(const Vector4 *a, const Vector4 *b);

bool vector4_is_equal(const Vector4 *a, const Vector4 *b);

void vector4_linear_interpolate(Vector4 *a, const Vector4 *b, const float weight);

float vector4_distance_squared(const Vector4 *a, const Vector4 *b);

float vector4_distance(const Vector4 *a, const Vector4 *b);

float vector4_length_squared(const Vector4 *a);

float vector4_length(const Vector4 *a);

void vector4_direction(Vector4 *a, const Vector4 *b);

void vector4_normalize(Vector4 *vector4);

#endif
