
#include "QRunnable.h"
#include "QProgram.h"

#include <iostream>
#include <memory>
using namespace std;

// VAO : Vertex Array Object
#define numVAOs 1
GLuint vao[numVAOs];

unique_ptr<QProgram> renderingProgram;

int point_init(GLFWwindow* window) {
	renderingProgram.reset(new QProgram());

	if (!renderingProgram->attachShaderFromFile("vertShader.glsl", "fragShader.glsl")) {
		cout << "Failed to create shader program" << endl;
		return -1;
	}

	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);

	return 0;
}

void point_deinit() {
	renderingProgram.release();
}

void point_display(GLFWwindow* window, double currentTime) {
	if (renderingProgram->isValid()) {
		renderingProgram->Use();
	}

	glPointSize(40.0f);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

QRunnable point_runnable() {
	return QRunnable(point_display, "Chapter2 - program2", point_init, point_deinit);
}
