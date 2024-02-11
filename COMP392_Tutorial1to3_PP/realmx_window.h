#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace realm
{
	class RealmXWindow
	{
	public:
		RealmXWindow(int width, int height, std::string windowName);
		~RealmXWindow();

		RealmXWindow(const RealmXWindow&) = delete;
		RealmXWindow &operator=(const RealmXWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}