#pragma once

#include "realmx_window.h"
#include "realmx_pipeline.h"

namespace realm
{
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run() ;

	private:
		RealmXWindow window{ WIDTH, HEIGHT, "Hello Vulkan!" };
		RealmXPipeline pipeline{ "Shaders/simple_shader_vert.spv", "Shaders/simple_shader_frag.spv" };
	};
}

