#pragma once
#include <GL/glew.h>

class QShader {

public:
	QShader(GLenum type, const char* shaderSource) {
		m_shader = glCreateShader(type);
		glShaderSource(m_shader, 1, &shaderSource, nullptr);
		glCompileShader(m_shader);
	}

	~QShader() {
		if (m_shader != 0) {
			glDeleteShader(m_shader);
		}
	}

public:
	GLuint id() const { return m_shader; }
private:
	GLuint m_shader = 0;
};
