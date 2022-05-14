//
// Created by Steven Hart on 14/5/2022.
//

#ifndef SPEED_TEXT_PIPELINE_HPP
#define SPEED_TEXT_PIPELINE_HPP

#include <string>
#include <vector>

namespace vulkan_engine{
    class Pipeline {
    public:
        Pipeline(const std::string& vertFilepath, const std::string& fragFilepath);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
    };
}

#endif //SPEED_TEXT_PIPELINE_HPP
