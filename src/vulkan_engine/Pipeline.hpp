//
// Created by Steven Hart on 14/5/2022.
//

#ifndef SPEED_TEXT_PIPELINE_HPP
#define SPEED_TEXT_PIPELINE_HPP

#include "Device.hpp"

// std
#include <string>
#include <vector>

namespace vulkan_engine{
    struct PipelineConfigInfo {};
    class Pipeline {
    public:
        Pipeline(Device &device,
                 const std::string& vertFilepath,
                 const std::string& fragFilepath,
                 const PipelineConfigInfo& configInfo);
        ~Pipeline() {}
        Pipeline(const Pipeline&) = delete;
        void operator=(const Pipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath,
                                    const std::string& fragFilepath,
                                    const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
        Device& device;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}

#endif //SPEED_TEXT_PIPELINE_HPP
