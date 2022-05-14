//
// Created by Steven Hart on 14/5/2022.
//

#ifndef SPEED_TEXT_WINDOW_HPP
#define SPEED_TEXT_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <string>

namespace vulkan_engine{
    class Window {
    public:
        Window(int width, int height, std::string name);
        ~Window();

        Window(const Window&) = delete;
        Window &operator=(const Window&) = delete;

        bool shouldClose() {return glfwWindowShouldClose(window);}
    private:
        void initWindow();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}



#endif //SPEED_TEXT_WINDOW_HPP
