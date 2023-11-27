#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdbool.h>

typedef struct Vector3{
    union { 
        struct {
            float x;
            float y;
            float z;
        };
        float buffer[3];
    };
} Vector3;

Vector3 *vector3_new(const float x, const float y, const float z);

void vector3_free(Vector3 *vector3);

Vector3 *vector3_clone(const Vector3 *vector3);

void vector3_copy(Vector3 *a, const Vector3 *b);

void vector3_set(Vector3 *vector3, const float x, const float y, const float z);

float vector3_get_x(const Vector3 *vector3);
void vector3_set_x(Vector3 *vector3, const float value);

float vector3_get_y(const Vector3 *vector3);
void vector3_set_y(Vector3 *vector3, const float value);

float vector3_get_z(const Vector3 *vector3);
void vector3_set_z(Vector3 *vector3, const float value);

void vector3_add(Vector3 *a, const Vector3 *b);

void vector3_subtract(Vector3 *a, const Vector3 *b);

void vector3_multiply(Vector3 *a, const Vector3 *b);

void vector3_divide(Vector3 *a, const Vector3 *b);

void vector3_modulus(Vector3 *a, const Vector3 *b);

void vector3_add_scalar(Vector3 *vector3, const float scalar);

void vector3_multiply_scalar(Vector3 *vector3, const float scalar);

void vector3_divide_scalar(Vector3 *vector3, const float scalar);

void vector3_inverse(Vector3 *vector3);

void vector3_cross(Vector3 *a, const Vector3 *b);

float vector3_dot(const Vector3 *a, const Vector3 *b);

bool vector3_is_equal(const Vector3 *a, const Vector3 *b);

void vector3_linear_interpolate(Vector3 *a, const Vector3 *b, const float weight);

float vector3_distance_squared(const Vector3 *a, const Vector3 *b);

float vector3_distance(const Vector3 *a, const Vector3 *b);

float vector3_length_squared(const Vector3 *a);

float vector3_length(const Vector3 *a);

void vector3_direction(Vector3 *a, const Vector3 *b);

void vector3_normalize(Vector3 *vector3);

float vector3_angle(const Vector3 *a, const Vector3 *b);

#endif
