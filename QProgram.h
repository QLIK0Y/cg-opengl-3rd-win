#pragma once

#include "QShader.h"

class QProgram {
public:
	//QProgram() = default;

	QProgram(const char* vshaderSource, const char* fshaderSource) {
		QShader vShader(GL_VERTEX_SHADER, vshaderSource);
		QShader fShader(GL_FRAGMENT_SHADER, fshaderSource);

		this->QProgram::QProgram(vShader, fShader);
	}

	QProgram(QShader& vertexShader, QShader& fragmentShader) {
		m_program = glCreateProgram();

		glAttachShader(m_program, vertexShader.id());
		glAttachShader(m_program, fragmentShader.id());

		glLinkProgram(m_program);
	}

	~QProgram() {
		if (m_program != 0) {
			glDeleteProgram(m_program);
		}
	}

public:
	void Use() const {
		glUseProgram(m_program);
	}

	//GLuint id() const { return m_program; }

private:
	GLuint m_program = 0;

};