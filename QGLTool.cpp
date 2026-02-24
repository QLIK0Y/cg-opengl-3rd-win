#include "QGLTool.h"

#include <iostream>
using namespace std;

bool QGLTool::checkGLError()
{
	bool hasError = false;
	GLenum err = glGetError();
	while (err != GL_NO_ERROR) {
		cout << "OpenGL error: " << err << endl;
		hasError = true;

		err = glGetError();
	}
	return hasError;
}

void QGLTool::outputShaderLog(GLuint shader) {
	GLint logLength = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0) {
		char* log = new char[logLength];
		int chWritten = 0;
		glGetShaderInfoLog(shader, logLength, &chWritten, log);
		cout << "Shader Info Log: " << log << endl;
		delete[] log;
	}
}

void QGLTool::outputProgramLog(GLuint program) {
	GLint logLength = 0;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0) {
		char* log = new char[logLength];
		int chWritten = 0;
		glGetProgramInfoLog(program, logLength, &chWritten, log);
		cout << "Program Info Log: " << log << endl;
		delete[] log;
	}
}