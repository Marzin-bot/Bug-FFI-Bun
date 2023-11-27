import * as FFI from "../FFI.mjs";

const registry = new FinalizationRegistry((pointer) => {
    FFI.vector3_free(pointer);
});

export default class Vector3{
    #ptr;
    constructor (x = 0, y = 0, z = 0){
        this.#ptr = FFI.vector3_new(x, y, z);
        registry.register(this, this.#ptr);
    }

    get_pointer(){
        return this.#ptr;
    }
    
    get x(){
        return FFI.vector3_get_x(this.#ptr);
    }
    set x(new_x){
        FFI.vector3_set_x(this.#ptr, new_x);
    }

    get y(){
        return FFI.vector3_get_y(this.#ptr);
    }
    set y(new_y){
        FFI.vector3_set_y(this.#ptr, new_y);
    }

    get z(){
        return FFI.vector3_get_z(this.#ptr);
    }
    set z(new_z){
        FFI.vector3_set_z(this.#ptr, new_z);
    }

    clone(){
        return new Vector3(this.x, this.y, this.z);
    }

    copy(vector3_source){
        FFI.vector3_copy(this.#ptr, vector3_source.get_pointer());
        return this;
    }

    set(x, y, z){
        FFI.vector3_set(this.#ptr, x, y, z);
        return this;
    }

    add(vector3){
        FFI.vector3_add(this.#ptr, vector3.get_pointer());
        return this;
    }

    subtract(vector3){
        FFI.vector3_subtract(this.#ptr, vector3.get_pointer());
        return this;
    }

    multiply(vector3){
        FFI.vector3_multiply(this.#ptr, vector3.get_pointer());
        return this;
    }

    divide(vector3){
        FFI.vector3_divide(this.#ptr, vector3.get_pointer());
        return this;
    }

    modulus(vector3){
        FFI.vector3_modulus(this.#ptr, vector3.get_pointer());
        return this;
    }

    pow(vector3){
        this.x **= vector3.x;
        this.y **= vector3.y;
        this.z **= vector3.z;
        return this;
    }

    add_scalar(scalar){
        FFI.vector3_add_scalar(this.#ptr, scalar);
        return this;
    }

    multiply_scalar(scalar){
        FFI.vector3_multiply_scalar(this.#ptr, scalar);
        return this;
    }

    divide_scalar(scalar){
        FFI.vector3_divide_scalar(this.#ptr, scalar);
        return this;
    }

    inverse(){
        FFI.vector3_inverse(this.#ptr);
        return this;
    }

    cross(vector3){
        FFI.vector3_cross(this.#ptr, vector3.get_pointer());
        return this;
    }

    dot(vector3){
        return FFI.vector3_dot(this.#ptr, vector3.get_pointer());
    }

    is_equal_to(vector3){
        return FFI.vector3_is_equal(this.#ptr, vector3.get_pointer());
    }

    linear_interpolate(to, weight){
        FFI.vector3_linear_interpolate(this.#ptr, to.get_pointer(), weight);
        return this;
    }

    distance_squared_to(vector3){
        return FFI.vector3_distance_squared(this.#ptr, vector3.get_pointer());
    }

    distance_to(vector3){
        return FFI.vector3_distance(this.#ptr, vector3.get_pointer());
    }

    direction_to(vector3){
        FFI.vector3_direction(this.#ptr, vector3.get_pointer());
        return this;
    }

    length(){
        return FFI.vector3_length(this.#ptr);
    }

    length_squared(){
        return FFI.vector3_length_squared(this.#ptr);
    }

    normalize(){
        FFI.vector3_normalize(this.#ptr);
        return this;
    }

    angle_to(vector3){
        return FFI.vector3_angle(this.#ptr, vector3.get_pointer());
    }
}
