#include "realmx_window.h"
#include <stdexcept>

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

	void RealmXWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create window surface!");
		}
	}
}
