

#include "QApp.h"

#include <iostream>
using namespace std;

int QApp::Init() {
	if (!glfwInit()) {
		cerr << "Failed to initialize GLFW" << endl;
		return -1;
	}

	m_initialized = true;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_majorVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_minorVersion);

	m_window = glfwCreateWindow(m_runnable.width, m_runnable.height, m_runnable.title, nullptr, nullptr);
	if (!m_window) {
		cerr << "Failed to create GLFW window" << endl;
		return -1;
	}

	glfwMakeContextCurrent(m_window);
	if (glewInit() != GLEW_OK) {
		cerr << "Failed to initialize GLEW" << endl;
		return -1;
	}

	if (m_runnable.init != nullptr) {
		return m_runnable.init(m_window);
	}

	return 0;
}


int QApp::Run() {
	while (!glfwWindowShouldClose(m_window)) {

		if (m_runnable.display != nullptr) {
			m_runnable.display(m_window, glfwGetTime());
		}

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	return 0;
}
