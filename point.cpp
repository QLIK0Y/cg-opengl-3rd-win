
#include "QRunnable.h"


#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram() {
	const char* vshaderSource = R"(
		#version 430
		void main(void)
		{
			gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
		}
	)";
	const char* fshaderSource = R"(
		#version 430
		out vec4 color;
		void main(void)
		{
			color = vec4(1.0, 0.0, 0.0, 1.0);
		}
	)";

	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vshaderSource, nullptr);
	glCompileShader(vShader);

	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fshaderSource, nullptr);
	glCompileShader(fShader);

	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);

	return vfProgram;
}

int point_init(GLFWwindow* window) {
	renderingProgram = createShaderProgram();
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);

	return 0;
}

void point_display(GLFWwindow* window, double currentTime) {
	glUseProgram(renderingProgram);
	glPointSize(40.0f);
	glDrawArrays(GL_POINTS, 0, 1);
}

QRunnable point_runnable() {
	return QRunnable(point_display, "Chapter2 - program2", point_init);
}
