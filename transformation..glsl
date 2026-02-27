// builds and returns a translation matrix
mat4 buildTranslate(float x, float y, float z) {
    return mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        x, y, z, 1.0
    );
}

// builds and returns a matrix that performs a rotation around the X axis
mat4 buildRotateX(float rad) {
    return mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, cos(rad), -sin(rad), 0.0,
        1.0, sin(rad), cos(rad), 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

// builds and returns a matrix that performs a rotation around the Y axis
mat4 buildRotateY(float rad) {
    return mat4(        
        cos(rad), 0.0, sin(rad), 0.0, 
        0.0, 1.0, 0.0, 0.0,
        -sin(rad), 0.0, cos(rad), 0.0, 
        0.0, 0.0, 0.0, 1.0
    );
}

// builds and returns a matrix that performs a rotation around the Z axis
mat4 buildRotateZ(float rad) {
    return mat4(        
        cos(rad), -sin(rad), 0.0, 0.0, 
        sin(rad), cos(rad), 0.0, 0.0, 
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

// builds and returns a scale matrix
mat4 buildScale(float x, float y, float z) {
    return mat4(        
        x, 0.0, 0.0, 0.0, 
        0.0, y, 0.0, 0.0, 
        0.0, 0.0, z, 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}
