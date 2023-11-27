#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "matrix4x4.h"
#include "vector3.h"
#include "vector4.h"

Matrix4x4 *matrix4x4_new(){
    Matrix4x4 *mat4 = (Matrix4x4 *)malloc(sizeof(Matrix4x4));
    if (mat4){
        matrix4x4_set(
            mat4,
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }
    return mat4;
}

void matrix4x4_free(Matrix4x4 *matrix4x4){
    free(matrix4x4);
}

Matrix4x4 *matrix4x4_clone(const Matrix4x4 *mat4){
    Matrix4x4 *result = matrix4x4_new();
    matrix4x4_copy(result, mat4);

    return result;
}

void matrix4x4_copy(Matrix4x4 *a, const Matrix4x4 *b){
    matrix4x4_set(a, b->xx, b->xy, b->xz, b->xw, b->yx, b->yy, b->yz, b->yw, b->zx, b->zy, b->zz, b->zw, b->wx, b->wy, b->wz, b->ww);
}

void matrix4x4_set(Matrix4x4 *mat4, const float xx, const float xy, const float xz, const float xw, const float yx, const float yy, const float yz, const float yw, const float zx, const float zy, const float zz, const float zw, const float wx, const float wy, const float wz, const float ww){
    mat4->xx = xx; mat4->xy = xy; mat4->xz = xz; mat4->xz = xw;
    mat4->yx = yx; mat4->yy = yy; mat4->yz = yz; mat4->xz = yw;
    mat4->zx = zx; mat4->zy = zy; mat4->zz = zz; mat4->xz = zw;
    mat4->wx = wx; mat4->wy = wy; mat4->wz = wz; mat4->xz = ww;
}

void matrix4x4_multiply(Matrix4x4 *a, const Matrix4x4 *b){
    const float a00 = a->xx, a01 = a->xy, a02 = a->xz, a03 = a->xw;
    const float a10 = a->yx, a11 = a->yy, a12 = a->yz, a13 = a->yw;
    const float a20 = a->zx, a21 = a->zy, a22 = a->zz, a23 = a->zw;
    const float a30 = a->wx, a31 = a->wy, a32 = a->wz, a33 = a->ww;

    float b0 = b->xx, b1 = b->xy, b2 = b->xz, b3 = b->xw;
    a->xx = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
    a->xy = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
    a->xz = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
    a->xw = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;
    
    b0 = b->yx, b1 = b->yy, b2 = b->yz, b3 = b->yw;
    a->yx = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
    a->yy = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
    a->yz = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
    a->yw = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;

    b0 = b->zx, b1 = b->zy, b2 = b->zz, b3 = b->zw;
    a->zx = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
    a->zy = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
    a->zz = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
    a->zw = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;

    b0 = b->wx, b1 = b->wy, b2 = b->wz, b3 = b->ww;
    a->wx = b0 * a00 + b1 * a10 + b2 * a20 + b3 * a30;
    a->wy = b0 * a01 + b1 * a11 + b2 * a21 + b3 * a31;
    a->wz = b0 * a02 + b1 * a12 + b2 * a22 + b3 * a32;
    a->ww = b0 * a03 + b1 * a13 + b2 * a23 + b3 * a33;
}

void matrix4x4_multiply_vector4(const Matrix4x4 *mat4, Vector4 *p_vec4){
    const float v_x = p_vec4->x;
    const float v_y = p_vec4->y;
    const float v_z = p_vec4->z;
    const float v_w = p_vec4->w;

    p_vec4->x = mat4->xx * v_x + mat4->yx * v_y + mat4->zx * v_z + mat4->wx * v_w;
    p_vec4->y = mat4->xy * v_x + mat4->yy * v_y + mat4->zy * v_z + mat4->wy * v_w;
    p_vec4->z = mat4->xz * v_x + mat4->yz * v_y + mat4->zz * v_z + mat4->wz * v_w;
    p_vec4->w = mat4->xw * v_x + mat4->yw * v_y + mat4->zw * v_z + mat4->ww * v_w;
}

void matrix4x4_invert(Matrix4x4 *matrix4x4){
    const float a00 = matrix4x4->xx, a01 = matrix4x4->xy, a02 = matrix4x4->xz, a03 = matrix4x4->xw;
    const float a10 = matrix4x4->yx, a11 = matrix4x4->yy, a12 = matrix4x4->yz, a13 = matrix4x4->yw;
    const float a20 = matrix4x4->zx, a21 = matrix4x4->zy, a22 = matrix4x4->zz, a23 = matrix4x4->zw;
    const float a30 = matrix4x4->wx, a31 = matrix4x4->wy, a32 = matrix4x4->wz, a33 = matrix4x4->ww;
    const float b00 = a00 * a11 - a01 * a10;
    const float b01 = a00 * a12 - a02 * a10;
    const float b02 = a00 * a13 - a03 * a10;
    const float b03 = a01 * a12 - a02 * a11;
    const float b04 = a01 * a13 - a03 * a11;
    const float b05 = a02 * a13 - a03 * a12;
    const float b06 = a20 * a31 - a21 * a30;
    const float b07 = a20 * a32 - a22 * a30;
    const float b08 = a20 * a33 - a23 * a30;
    const float b09 = a21 * a32 - a22 * a31;
    const float b10 = a21 * a33 - a23 * a31;
    const float b11 = a22 * a33 - a23 * a32;
    
    float det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    if (!det){
        return;
    }

    det = 1.0 / det;
    
    matrix4x4_set(
        matrix4x4,
        (a11 * b11 - a12 * b10 + a13 * b09) * det,
        (a02 * b10 - a01 * b11 - a03 * b09) * det,
        (a31 * b05 - a32 * b04 + a33 * b03) * det,
        (a22 * b04 - a21 * b05 - a23 * b03) * det,
        (a12 * b08 - a10 * b11 - a13 * b07) * det,
        (a00 * b11 - a02 * b08 + a03 * b07) * det,
        (a32 * b02 - a30 * b05 - a33 * b01) * det,
        (a20 * b05 - a22 * b02 + a23 * b01) * det,
        (a10 * b10 - a11 * b08 + a13 * b06) * det,
        (a01 * b08 - a00 * b10 - a03 * b06) * det,
        (a30 * b04 - a31 * b02 + a33 * b00) * det,
        (a21 * b02 - a20 * b04 - a23 * b00) * det,
        (a11 * b07 - a10 * b09 - a12 * b06) * det,
        (a00 * b09 - a01 * b07 + a02 * b06) * det,
        (a31 * b01 - a30 * b03 - a32 * b00) * det,
        (a20 * b03 - a21 * b01 + a22 * b00) * det
    );
}

void matrix4x4_get_scale(const Matrix4x4 *matrix4x4, Vector3 *dest_scale){
    dest_scale->x = sqrtf(matrix4x4->xx + matrix4x4->xy + matrix4x4->xz);
    dest_scale->y = sqrtf(matrix4x4->yx + matrix4x4->yy + matrix4x4->yz);
    dest_scale->z = sqrtf(matrix4x4->zx + matrix4x4->zy + matrix4x4->zz);
}
void matrix4x4_set_scale(Matrix4x4 *matrix4x4, const Vector3 *new_scale){
    const float a00 = matrix4x4->xx * new_scale->x, a01 = matrix4x4->xy * new_scale->x, a02 = matrix4x4->xz * new_scale->x;
    const float a10 = matrix4x4->yx * new_scale->y, a11 = matrix4x4->yy * new_scale->y, a12 = matrix4x4->yz * new_scale->y;
    const float a20 = matrix4x4->zx * new_scale->z, a21 = matrix4x4->zy * new_scale->z, a22 = matrix4x4->zz * new_scale->z;

    matrix4x4->xx = a00, matrix4x4->xy = a01, matrix4x4->xz = a02;
    matrix4x4->yx = a10, matrix4x4->yy = a11, matrix4x4->yz = a12;
    matrix4x4->zx = a20, matrix4x4->zy = a21, matrix4x4->zz = a22;
}

void matrix4x4_get_origin(const Matrix4x4 *matrix4x4, Vector3 *dest_origin){
    dest_origin->x = matrix4x4->wx;
    dest_origin->y = matrix4x4->wy;
    dest_origin->z = matrix4x4->wz;
}
void matrix4x4_set_origin(Matrix4x4 *matrix4x4, const Vector3 *new_origin){
    matrix4x4->wx = new_origin->x;
    matrix4x4->wy = new_origin->y;
    matrix4x4->wz = new_origin->z;
}

void matrix4x4_translate(Matrix4x4 *matrix4x4, const Vector3 *translation){
    matrix4x4->wx += translation->x;
    matrix4x4->wy += translation->y;
    matrix4x4->wz += translation->z;
}

bool matrix4x4_is_equal(const Matrix4x4 *mat4_a, const Matrix4x4 *mat4_b){
    return (
        mat4_a->xx == mat4_b->xx && mat4_a->xy == mat4_b->xy && mat4_a->xz == mat4_b->xz && mat4_a->xw == mat4_b->xw &&
        mat4_a->yx == mat4_b->yx && mat4_a->yy == mat4_b->yy && mat4_a->yz == mat4_b->yz && mat4_a->yw == mat4_b->yw &&
        mat4_a->zx == mat4_b->zx && mat4_a->zy == mat4_b->zy && mat4_a->zz == mat4_b->zz && mat4_a->zw == mat4_b->zw &&
        mat4_a->wx == mat4_b->wx && mat4_a->wy == mat4_b->wy && mat4_a->wz == mat4_b->wz && mat4_a->ww == mat4_b->ww
    );
}

float matrix4x4_get_xx(const Matrix4x4 *matrix4x4){
    return matrix4x4->xx;
}
void matrix4x4_set_xx(Matrix4x4 *matrix4x4, float xx){
    matrix4x4->xx = xx;
}

float matrix4x4_get_xy(const Matrix4x4 *matrix4x4){
    return matrix4x4->xy;
}
void matrix4x4_set_xy(Matrix4x4 *matrix4x4, float xy){
    matrix4x4->xy = xy;
}

float matrix4x4_get_xz(const Matrix4x4 *matrix4x4){
    return matrix4x4->xz;
}
void matrix4x4_set_xz(Matrix4x4 *matrix4x4, float xz){
    matrix4x4->xz = xz;
}

float matrix4x4_get_xw(const Matrix4x4 *matrix4x4){
    return matrix4x4->xw;
}
void matrix4x4_set_xw(Matrix4x4 *matrix4x4, float xw){
    matrix4x4->xw = xw;
}


float matrix4x4_get_yx(const Matrix4x4 *matrix4x4){
    return matrix4x4->yx;
}
void matrix4x4_set_yx(Matrix4x4 *matrix4x4, float yx){
    matrix4x4->yx = yx;
}

float matrix4x4_get_yy(const Matrix4x4 *matrix4x4){
    return matrix4x4->yy;
}
void matrix4x4_set_yy(Matrix4x4 *matrix4x4, float yy){
    matrix4x4->yy = yy;
}

float matrix4x4_get_yz(const Matrix4x4 *matrix4x4){
    return matrix4x4->yz;
}
void matrix4x4_set_yz(Matrix4x4 *matrix4x4, float yz){
    matrix4x4->yz = yz;
}

float matrix4x4_get_yw(const Matrix4x4 *matrix4x4){
    return matrix4x4->yw;
}
void matrix4x4_set_yw(Matrix4x4 *matrix4x4, float yw){
    matrix4x4->yw = yw;
}


float matrix4x4_get_zx(const Matrix4x4 *matrix4x4){
    return matrix4x4->zx;
}
void matrix4x4_set_zx(Matrix4x4 *matrix4x4, float zx){
    matrix4x4->zx = zx;
}

float matrix4x4_get_zy(const Matrix4x4 *matrix4x4){
    return matrix4x4->zy;
}
void matrix4x4_set_zy(Matrix4x4 *matrix4x4, float zy){
    matrix4x4->zy = zy;
}

float matrix4x4_get_zz(const Matrix4x4 *matrix4x4){
    return matrix4x4->zz;
}
void matrix4x4_set_zz(Matrix4x4 *matrix4x4, float zz){
    matrix4x4->zz = zz;
}

float matrix4x4_get_zw(const Matrix4x4 *matrix4x4){
    return matrix4x4->zw;
}
void matrix4x4_set_zw(Matrix4x4 *matrix4x4, float zw){
    matrix4x4->zw = zw;
}


float matrix4x4_get_wx(const Matrix4x4 *matrix4x4){
    return matrix4x4->wx;
}
void matrix4x4_set_wx(Matrix4x4 *matrix4x4, float wx){
    matrix4x4->wx = wx;
}

float matrix4x4_get_wy(const Matrix4x4 *matrix4x4){
    return matrix4x4->wy;
}
void matrix4x4_set_wy(Matrix4x4 *matrix4x4, float wy){
    matrix4x4->wy = wy;
}

float matrix4x4_get_wz(const Matrix4x4 *matrix4x4){
    return matrix4x4->wz;
}
void matrix4x4_set_wz(Matrix4x4 *matrix4x4, float wz){
    matrix4x4->wz = wz;
}

float matrix4x4_get_ww(const Matrix4x4 *matrix4x4){
    return matrix4x4->ww;
}
void matrix4x4_set_ww(Matrix4x4 *matrix4x4, float ww){
    matrix4x4->ww = ww;
}