//
// Created by Steven Hart on 14/5/2022.
//

#include "Pipeline.hpp"
//std
#include <fstream>
#include <stdexcept>
#include <iostream>


#ifndef ENGINE_PATH
#define ENGINE_PATH "../"
#endif

namespace vulkan_engine{
    Pipeline::Pipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        createGraphicsPipeline(vertFilepath, fragFilepath);
    }

    std::vector<char> Pipeline::readFile(const std::string& filepath){
        std::string enginePath = ENGINE_PATH + filepath;
        // seek end, read as binary
        std::ifstream file{enginePath, std::ios::ate | std::ios::binary};

        if(!file.is_open()){
            throw std::runtime_error("failed to open file: " + enginePath);
        }

        // get file size based on read position
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        // read file into buffer
        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    }

    void Pipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        auto vertCode = readFile(vertFilepath);
        auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex shader code size: " << vertCode.size() << "\n";
        std::cout << "Fragment shader code size: " << fragCode.size() << "\n";
    }
}
