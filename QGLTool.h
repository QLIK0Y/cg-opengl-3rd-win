#pragma once

#include <GL/glew.h>

class QGLTool
{
public:
	static bool checkGLError();
	static void outputShaderLog(GLuint shader);
	static void outputProgramLog(GLuint program);
};

