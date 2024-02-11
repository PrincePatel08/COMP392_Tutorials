#include "realmx_window.h"

namespace realm
{
	RealmXWindow::RealmXWindow(int width, int height, std::string windowName) : width(width), height(height), windowName(windowName)
	{
		initWindow();
	}

	RealmXWindow::~RealmXWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void RealmXWindow::initWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}