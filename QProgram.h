#pragma once

#include "QShader.h"

class QProgram {
public:
	QProgram();
	~QProgram();

public:
	bool attachShader(QShader& vertexShader, QShader& fragmentShader);
	bool attachShaderSource(const char* vshaderSource, const char* fshaderSource);
	bool attachShaderFromFile(const char* vshaderFile, const char* fshaderFile);

	void Use() const;

	bool isValid() const { return m_program != 0 && m_isValid; }

	bool isLinked() const;

	//GLuint id() const { return m_program; }

	void outputProgramLog();

private:
	GLuint m_program = 0;
	bool m_isValid = false;

};