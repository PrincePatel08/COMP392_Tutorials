#pragma once

#include "realmx_device.h"
#include <string>
#include <vector>

namespace realm
{
	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class RealmXPipeline
	{
	public:
		RealmXPipeline(RealmXDevice &device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		~RealmXPipeline();
		
		RealmXPipeline(const RealmXPipeline&) = delete;
		RealmXPipeline &operator=(const RealmXPipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo);
		
		void createShaderModule(const std::vector<char>& code, VkShaderModule *shaderModule);

		RealmXDevice& device;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}

