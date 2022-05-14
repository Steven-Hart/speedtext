//
// Created by Steven Hart on 14/5/2022.
//

#include "Window.hpp"
namespace vulkan_engine{
    Window::Window(int width, int height, std::string name) : width{width}, height{height}, windowName{name} {
        initWindow();
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::initWindow() {
        // Initialise glfw library
        glfwInit();
        // Disable default API (opengl)
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Disable resizing: to be handled later
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}
