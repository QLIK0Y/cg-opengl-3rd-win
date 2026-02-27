#version 430

// #include <transformation..glsl>  not support

uniform float offset;
uniform float rad;

mat4 buildRotateX(float rad) {
    return mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, cos(rad), -sin(rad), 0.0,
        1.0, sin(rad), cos(rad), 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

void main(void)
{
	if (gl_VertexID == 0) {
		gl_Position = vec4(0.0 + offset, 0.25, 0.0, 1.0);	
	} else if (gl_VertexID == 1) {
		gl_Position = vec4(-0.25 + offset, -0.25, 0.0, 1.0);	
	} else {
		gl_Position = vec4(0.25 + offset, -0.25, 0.0, 1.0);
	}

	gl_Position = gl_Position * buildRotateX(rad);
}