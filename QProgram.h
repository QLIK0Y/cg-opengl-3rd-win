#pragma once

#include "QShader.h"

class QProgram {
public:
	//QProgram() = default;

	QProgram(const char* vshaderSource, const char* fshaderSource);

	QProgram(QShader& vertexShader, QShader& fragmentShader);

	~QProgram();

public:
	void Use() const;

	bool isValid() const { return m_program != 0 && m_isValid; }

	bool isLinked() const;

	//GLuint id() const { return m_program; }

	void outputProgramLog();

private:
	GLuint m_program = 0;
	bool m_isValid = false;

};