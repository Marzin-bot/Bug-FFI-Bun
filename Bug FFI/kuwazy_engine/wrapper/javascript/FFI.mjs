import {dlopen, FFIType, suffix} from "bun:ffi";

const path = `kuwazy_engine/kuwazy_engine.${suffix}`;

export const {
    symbols: {
        // Vector3.
        vector3_new,
        vector3_free,
        vector3_clone,
        vector3_copy,
        vector3_set,
        vector3_get_x,
        vector3_set_x,
        vector3_get_y,
        vector3_set_y,
        vector3_get_z,
        vector3_set_z,
        vector3_add,
        vector3_subtract,
        vector3_multiply,
        vector3_divide,
        vector3_modulus,
        vector3_add_scalar,
        vector3_multiply_scalar,
        vector3_divide_scalar,
        vector3_inverse,
        vector3_cross,
        vector3_dot,
        vector3_is_equal,
        vector3_linear_interpolate,
        vector3_distance_squared,
        vector3_distance,
        vector3_length_squared,
        vector3_length,
        vector3_direction,
        vector3_normalize,
        vector3_angle,

        // Vector4.
        vector4_new,
        vector4_free,
        vector4_clone,
        vector4_copy,
        vector4_set,
        vector4_get_x,
        vector4_set_x,
        vector4_get_y,
        vector4_set_y,
        vector4_get_z,
        vector4_set_z,
        vector4_get_w,
        vector4_set_w,
        vector4_add,
        vector4_subtract,
        vector4_multiply,
        vector4_divide,
        vector4_modulus,
        vector4_add_scalar,
        vector4_multiply_scalar,
        vector4_divide_scalar,
        vector4_inverse,
        vector4_dot,
        vector4_is_equal,
        vector4_linear_interpolate,
        vector4_distance_squared,
        vector4_distance,
        vector4_length_squared,
        vector4_length,
        vector4_direction,
        vector4_normalize,

        // AABB.
        aabb_new,
        aabb_free,
        aabb_get_position,
        aabb_set_position,
        aabb_get_size,
        aabb_set_size,
        aabb_intersects,
        aabb_encloses,
        aabb_get_center,
        aabb_grow,
        aabb_merge,
        aabb_is_equal,
        aabb_get_volume,
        aabb_get_endpoint,

        // Plane.
        plane_new,
        plane_free,
        plane_get_normal,
        plane_set_normal,
        plane_get_d,
        plane_set_d,
        plane_get_point_depth,
        plane_is_point_over
    },
} = dlopen(
    path,
    {
        // Vector3.
        vector3_new: {
            args: [FFIType.f32, FFIType.f32, FFIType.f32],
            returns: FFIType.ptr
        },
        vector3_free: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        vector3_clone: {
            args: [FFIType.ptr],
            returns: FFIType.ptr
        },
        vector3_copy: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_set: {
            args: [FFIType.ptr, FFIType.f32, FFIType.f32, FFIType.f32],
            returns: FFIType.void
        },
        vector3_get_x: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_set_x: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_get_y: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_set_y: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_get_z: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_set_z: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_add: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_subtract: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_multiply: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_divide: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_modulus: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_add_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_multiply_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_divide_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_inverse: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        vector3_cross: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_dot: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_is_equal: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        },
        vector3_linear_interpolate: {
            args: [FFIType.ptr, FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector3_distance_squared: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_distance: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_length_squared: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_length: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector3_direction: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector3_normalize: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        vector3_angle: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },

        // Vector4.
        vector4_new: {
            args: [FFIType.f32, FFIType.f32, FFIType.f32, FFIType.f32],
            returns: FFIType.ptr
        },
        vector4_free: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        vector4_clone: {
            args: [FFIType.ptr],
            returns: FFIType.ptr
        },
        vector4_copy: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_set: {
            args: [FFIType.ptr, FFIType.f32, FFIType.f32, FFIType.f32, FFIType.f32],
            returns: FFIType.void
        },
        vector4_get_x: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_set_x: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_get_y: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_set_y: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_get_z: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_set_z: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_get_w: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_set_w: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_add: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_subtract: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_multiply: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_divide: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_modulus: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_add_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_multiply_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_divide_scalar: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_inverse: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        vector4_dot: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_is_equal: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        },
        vector4_linear_interpolate: {
            args: [FFIType.ptr, FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        vector4_distance_squared: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_distance: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_length_squared: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_length: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        vector4_direction: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        vector4_normalize: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },

        // AABB.
        aabb_new: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.ptr
        },
        aabb_free: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        aabb_get_position: {
            args: [FFIType.ptr],
            returns: FFIType.ptr
        },
        aabb_set_position: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        aabb_get_size: {
            args: [FFIType.ptr],
            returns: FFIType.ptr
        },
        aabb_set_size: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        aabb_intersects: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        },
        aabb_encloses: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        },
        aabb_get_center: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        aabb_grow: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        aabb_merge: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        aabb_is_equal: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        },
        aabb_get_volume: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        aabb_get_endpoint: {
            args: [FFIType.ptr, FFIType.u8],
            returns: FFIType.ptr
        },

        // Plane.
        plane_new: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.ptr
        },
        plane_free: {
            args: [FFIType.ptr],
            returns: FFIType.void
        },
        plane_get_normal: {
            args: [FFIType.ptr],
            returns: FFIType.ptr
        },
        plane_set_normal: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.void
        },
        plane_get_d: {
            args: [FFIType.ptr],
            returns: FFIType.f32
        },
        plane_set_d: {
            args: [FFIType.ptr, FFIType.f32],
            returns: FFIType.void
        },
        plane_get_point_depth: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.f32
        },
        plane_is_point_over: {
            args: [FFIType.ptr, FFIType.ptr],
            returns: FFIType.bool
        }
    },
);