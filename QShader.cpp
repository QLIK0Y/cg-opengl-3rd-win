
#include "QShader.h"

QShader::QShader(GLenum type, const char* shaderSource) {
	m_shader = glCreateShader(type);
	glShaderSource(m_shader, 1, &shaderSource, nullptr);
	glCompileShader(m_shader);

	m_isCompiled = isCompiled();
	if (!m_isCompiled) {
		cout << "Failed to compile shader ~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << shaderSource << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		QGLTool::checkGLError();
		outputShaderLog();
	}
}

QShader::~QShader() {
	if (m_shader != 0) {
		glDeleteShader(m_shader);
	}
}

bool QShader::isCompiled() const {
	GLint compiled = 0;
	glGetShaderiv(m_shader, GL_COMPILE_STATUS, &compiled);
	return compiled != 0;
}

void QShader::outputShaderLog() const {
	GLint logLength = 0;
	glGetShaderiv(m_shader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0) {
		char* log = new char[logLength];
		int chWritten = 0;
		glGetShaderInfoLog(m_shader, logLength, &chWritten, log);
		cout << "Shader Info Log: " << log << endl;
		delete[] log;
	}
}
