#include "firstApp.h"
#include <stdexcept>


namespace realm
{
	FirstApp::FirstApp()
	{
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	FirstApp::~FirstApp()
	{
		vkDestroyPipelineLayout(realmxDevice.device(), pipelineLayout, nullptr);
	}

	void FirstApp::run()
	{
		while (!realmxWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}

	void FirstApp::createPipelineLayout()
	{
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(realmxDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}
	}

	void FirstApp::createPipeline()
	{
		auto pipelineConfig = RealmXPipeline::defaultPipelineConfigInfo(realmxSwapChain.width(), realmxSwapChain.height());
		pipelineConfig.renderPass = realmxSwapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		realmxPipeline = std::make_unique<RealmXPipeline>(realmxDevice, "Shaders/simple_shader.vert.spv", "Shaders/simple_shader.frag.spv", pipelineConfig);
	}

	void FirstApp::createCommandBuffers()
	{
		/*commandBuffers.resize(swapChain.imageCount());
		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.commandPool = device.getCommandPool();
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
		if (vkAllocateCommandBuffers(device.device(), &allocInfo, commandBuffers.data()) != VK_SUCCESS) {
			throw std::runtime_error("failed to allocate command buffers!");
		}*/
	}

	void FirstApp::drawFrame()
	{
		/*uint32_t imageIndex;
		VkResult result = swapChain.acquireNextImage(&imageIndex);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("failed to acquire swap chain image!");
		}*/
	}
}
