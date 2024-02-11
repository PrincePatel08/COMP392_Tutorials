#pragma once

#include <string>
#include <vector>

namespace realm
{
	class RealmXPipeline
	{
	public:
		RealmXPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
		
		RealmXPipeline(const RealmXPipeline&) = delete;
		RealmXPipeline &operator=(const RealmXPipeline&) = delete;

	private:
		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	};
}

