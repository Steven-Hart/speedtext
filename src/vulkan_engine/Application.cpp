//
// Created by Steven Hart on 14/5/2022.
//

#include "Application.hpp"
namespace vulkan_engine{
    void Application::run() {
        while (!window.shouldClose()){
            glfwPollEvents();
        }
    }
}