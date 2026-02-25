#include "QProgram.h"


QProgram::QProgram() {
	m_program = glCreateProgram();
}

QProgram::~QProgram() {
	if (m_program != 0) {
		glDeleteProgram(m_program);
	}
}


bool QProgram::attachShader(QShader& vertexShader, QShader& fragmentShader) {
	glAttachShader(m_program, vertexShader.id());
	glAttachShader(m_program, fragmentShader.id());

	glLinkProgram(m_program);
	if (!isLinked()) {
		cout << "Linking failed" << endl;
		m_isValid = false;
		QGLTool::checkGLError();
		outputProgramLog();
	}

	m_isValid = true;

	return m_isValid;
}

bool QProgram::attachShaderSource(const char* vshaderSource, const char* fshaderSource) {
	QShader vShader, fShader;

	if ( vShader.compile(GL_VERTEX_SHADER, vshaderSource) 
		&& fShader.compile(GL_FRAGMENT_SHADER, fshaderSource)
		&& attachShader(vShader, fShader)) {
		return true;
	}

	return false;

}

bool QProgram::attachShaderFromFile(const char* vshaderFile, const char* fshaderFile) {
	QShader vShader, fShader;

	if (vShader.compileFromFile(GL_VERTEX_SHADER, vshaderFile)
		&& fShader.compileFromFile(GL_FRAGMENT_SHADER, fshaderFile)
		&& attachShader(vShader, fShader)) {
		return true;
	}

	return false;
}


void QProgram::Use() const {
	glUseProgram(m_program);
}


bool QProgram::isLinked() const {
	GLint linked = 0;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linked);
	return linked != 0;
}

void QProgram::outputProgramLog() {
	GLint logLength = 0;
	glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0) {
		char* log = new char[logLength];
		int chWritten = 0;
		glGetProgramInfoLog(m_program, logLength, &chWritten, log);
		cout << "Program Info Log: " << log << endl;
		delete[] log;
	}
}