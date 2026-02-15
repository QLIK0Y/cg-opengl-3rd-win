
#include "QRunnable.h"
#include "QProgram.h"

// VAO : Vertex Array Object
#define numVAOs 1
GLuint vao[numVAOs];

QProgram *renderingProgram = nullptr;

void createShaderProgram() {
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

	renderingProgram = new QProgram(vshaderSource, fshaderSource);
}

int point_init(GLFWwindow* window) {
	createShaderProgram();

	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);

	return 0;
}

void destroyShaderProgram() {
	delete renderingProgram;
	renderingProgram = nullptr;
}

void point_deinit() {
	destroyShaderProgram();
}

void point_display(GLFWwindow* window, double currentTime) {
	if (renderingProgram != nullptr) {
		renderingProgram->Use();
	}

	glPointSize(40.0f);
	glDrawArrays(GL_POINTS, 0, 1);
}

QRunnable point_runnable() {
	return QRunnable(point_display, "Chapter2 - program2", point_init, point_deinit);
}
