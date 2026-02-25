#pragma once

#include <GL/glew.h>
#include "QGLTool.h"
#include <iostream>
using namespace std;

class QShader {

public:
	QShader();

	~QShader();

public:
	bool compile(GLenum type, const char* shaderSource);
	bool compileFromFile(GLenum type, const char* filename);

	GLuint id() const { return m_shader; }
	bool isCompiled() const;

	bool isValid() const { return m_shader != 0 && m_isCompiled; }

	void outputShaderLog() const;

private:
	GLuint m_shader = 0;
	bool m_isCompiled = false;
};
