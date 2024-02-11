#include "firstApp.h"


namespace realm
{
	void FirstApp::run()
	{
		while (!window.shouldClose())
		{
			glfwPollEvents();
		}
	}
}
