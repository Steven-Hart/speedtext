#include "vulkan_engine/Application.hpp"
// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>


int main() {
    vulkan_engine::Application app{};
    try{
        app.run();
    } catch (const std::exception &e){
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}