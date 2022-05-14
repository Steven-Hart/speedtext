//
// Created by Steven Hart on 14/5/2022.
//

#ifndef SPEED_TEXT_APPLICATION_HPP
#define SPEED_TEXT_APPLICATION_HPP

#include "Window.hpp"
#include "Pipeline.hpp"

namespace vulkan_engine{
    class Application {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
    private:
        Window window{WIDTH, HEIGHT, "Hello Vulkan"};
        Pipeline pipeline{"shaders/compiled_shaders/simple_shader.vert.spv", "shaders/compiled_shaders/simple_shader.vert.spv"};
    };
}



#endif //SPEED_TEXT_APPLICATION_HPP
