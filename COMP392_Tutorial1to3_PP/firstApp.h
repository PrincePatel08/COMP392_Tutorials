#pragma once

#include "realmx_window.h"
#include "realmx_pipeline.h"
#include "realmx_device.h"
#include "realmx_swap_chain.h"

#include <memory>
#include <vector>

namespace realm
{
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

		void run() ;

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		RealmXWindow realmxWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		RealmXDevice realmxDevice{ realmxWindow };
		RealmXSwapChain realmxSwapChain{ realmxDevice, realmxWindow.getExtent() };
		std::unique_ptr<RealmXPipeline> realmxPipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}

