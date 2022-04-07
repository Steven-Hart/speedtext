cmake_minimum_required(VERSION 3.21)
project(speedtext)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include)
find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(speedtext main.cpp)

target_link_libraries(speedtext glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)

