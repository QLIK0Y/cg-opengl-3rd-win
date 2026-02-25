
#include "QRunnable.h"
#include "QProgram.h"
#include <iostream>
using namespace std;

// VAO : Vertex Array Object
#define numVAOs 1
GLuint vao[numVAOs];

QProgram *renderingProgram = nullptr;

bool createShaderProgram() {
	renderingProgram = new QProgram();

	return renderingProgram->attachShaderFromFile("vertShader.glsl", "fragShader.glsl") && renderingProgram->isValid();
}

int point_init(GLFWwindow* window) {
	if (!createShaderProgram()) {
		cout << "Failed to create shader program" << endl;
		return -1;
	}

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
