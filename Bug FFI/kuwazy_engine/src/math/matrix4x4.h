#ifndef MATRIX4X4_H
# define MATRIX4X4_H

# include <stdbool.h>
# include "vector3.h"
# include "vector4.h"

typedef struct {
    union {
        struct {
            float xx; float xy; float xz; float xw;
            float yx; float yy; float yz; float yw;
            float zx; float zy; float zz; float zw;
            float wx; float wy; float wz; float ww;
        };
        float buffer[16];
    };
} Matrix4x4;

Matrix4x4 *matrix4x4_new();

void matrix4x4_free(Matrix4x4 *matrix4x4);

Matrix4x4 *matrix4x4_clone(const Matrix4x4 *mat4);

void matrix4x4_copy(Matrix4x4 *a, const Matrix4x4 *b);

void matrix4x4_set(Matrix4x4 *mat4, const float xx, const float xy, const float xz, const float xw, const float yx, const float yy, const float yz, const float yw, const float zx, const float zy, const float zz, const float zw, const float wx, const float wy, const float wz, const float ww);

void matrix4x4_multiply(Matrix4x4 *a, const Matrix4x4 *b);

void matrix4x4_multiply_vector4(const Matrix4x4 *mat4, Vector4 *p_vec4);

void matrix4x4_invert(Matrix4x4 *matrix4x4);

void matrix4x4_get_scale(const Matrix4x4 *matrix4x4, Vector3 *dest_scale);

void matrix4x4_set_scale(Matrix4x4 *matrix4x4, const Vector3 *new_scale);

void matrix4x4_get_origin(const Matrix4x4 *matrix4x4, Vector3 *dest_origin);

void matrix4x4_set_origin(Matrix4x4 *matrix4x4, const Vector3 *new_origin);

void matrix4x4_translate(Matrix4x4 *matrix4x4, const Vector3 *translation);

bool matrix4x4_is_equal(const Matrix4x4 *a, const Matrix4x4 *b);

float matrix4x4_get_xx(const Matrix4x4 *matrix4x4);
void matrix4x4_set_xx(Matrix4x4 *matrix4x4, float xx);

float matrix4x4_get_xy(const Matrix4x4 *matrix4x4);
void matrix4x4_set_xy(Matrix4x4 *matrix4x4, float xy);

float matrix4x4_get_xz(const Matrix4x4 *matrix4x4);
void matrix4x4_set_xz(Matrix4x4 *matrix4x4, float xz);

float matrix4x4_get_xw(const Matrix4x4 *matrix4x4);
void matrix4x4_set_xw(Matrix4x4 *matrix4x4, float xw);


float matrix4x4_get_yx(const Matrix4x4 *matrix4x4);
void matrix4x4_set_yx(Matrix4x4 *matrix4x4, float yx);

float matrix4x4_get_yy(const Matrix4x4 *matrix4x4);
void matrix4x4_set_yy(Matrix4x4 *matrix4x4, float yy);

float matrix4x4_get_yz(const Matrix4x4 *matrix4x4);
void matrix4x4_set_yz(Matrix4x4 *matrix4x4, float yz);

float matrix4x4_get_yw(const Matrix4x4 *matrix4x4);
void matrix4x4_set_yw(Matrix4x4 *matrix4x4, float yw);


float matrix4x4_get_zx(const Matrix4x4 *matrix4x4);
void matrix4x4_set_zx(Matrix4x4 *matrix4x4, float zx);

float matrix4x4_get_zy(const Matrix4x4 *matrix4x4);
void matrix4x4_set_zy(Matrix4x4 *matrix4x4, float zy);

float matrix4x4_get_zz(const Matrix4x4 *matrix4x4);
void matrix4x4_set_zz(Matrix4x4 *matrix4x4, float zz);

float matrix4x4_get_zw(const Matrix4x4 *matrix4x4);
void matrix4x4_set_zw(Matrix4x4 *matrix4x4, float zw);


float matrix4x4_get_wx(const Matrix4x4 *matrix4x4);
void matrix4x4_set_wx(Matrix4x4 *matrix4x4, float wx);

float matrix4x4_get_wy(const Matrix4x4 *matrix4x4);
void matrix4x4_set_wy(Matrix4x4 *matrix4x4, float wy);

float matrix4x4_get_wz(const Matrix4x4 *matrix4x4);
void matrix4x4_set_wz(Matrix4x4 *matrix4x4, float wz);

float matrix4x4_get_ww(const Matrix4x4 *matrix4x4);
void matrix4x4_set_ww(Matrix4x4 *matrix4x4, float ww);

#endif
