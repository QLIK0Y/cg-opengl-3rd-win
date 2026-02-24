#include "QProgram.h"


QProgram::QProgram(const char* vshaderSource, const char* fshaderSource) {
	QShader vShader(GL_VERTEX_SHADER, vshaderSource);
	QShader fShader(GL_FRAGMENT_SHADER, fshaderSource);

	bool isValid = vShader.isValid() && fShader.isValid();

	if (isValid) {
		this->QProgram::QProgram(vShader, fShader);
	}
}

QProgram::QProgram(QShader& vertexShader, QShader& fragmentShader) {
	m_program = glCreateProgram();

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
}

QProgram::~QProgram() {
	if (m_program != 0) {
		glDeleteProgram(m_program);
	}
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