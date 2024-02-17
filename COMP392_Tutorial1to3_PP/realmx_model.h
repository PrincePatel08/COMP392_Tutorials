#pragma once

#include "realmx_device.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <vector>

namespace realm
{
	class RealmXModel
	{
		public:

			struct Vertex
			{
				glm::vec3 position;

				static std::vector<VkVertexInputBindingDescription> getBindingDescription();
				static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
			};

			RealmXModel(RealmXDevice& device, const std::vector<Vertex>& vertices);
			~RealmXModel();

			RealmXModel(const RealmXModel&) = delete;
			RealmXModel& operator=(const RealmXModel&) = delete;

			void bind(VkCommandBuffer commandBuffer);
			void draw(VkCommandBuffer commandBuffer);

		private:
			void createVertexBuffer(const std::vector<Vertex>& vertices);

			RealmXDevice& realmxDevice;
			VkBuffer vertexBuffer;
			VkDeviceMemory vertexBufferMemory;
			uint32_t vertexCount;
	};
}

