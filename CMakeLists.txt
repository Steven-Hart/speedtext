cmake_minimum_required(VERSION 3.21)

set(NAME speed-text)

message(STATUS "using ${CMAKE_GENERATOR}")
project(${NAME} VERSION 0.1.0)

#1. Get Vulkan
find_package(Vulkan REQUIRED)
message(STATUS "Found Vulkan: $ENV{VULKAN_SDK}")

#2. Get GLFW
find_package(glfw3 3.3 REQUIRED)
set(GLFW_LIB glfw)
message(STATUS "Found GLFW: ${GLFW_LIB}")

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE VULKAN_ENGINE_SOURCE ${PROJECT_SOURCE_DIR}/src/vulkan_engine/*.cpp)
file(GLOB_RECURSE VULKAN_ENGINE_INCLUDE ${PROJECT_SOURCE_DIR}/src/vulkan_engine/*.hpp)
set(VULKAN_ENGINE, ${VULKAN_ENGINE_SOURCE} ${VULKAN_ENGINE_INCLUDE})

add_executable(${PROJECT_NAME} ${SOURCES} ${VULKAN_ENGINE})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} glfw Vulkan::Vulkan)

# Build Shaders #
find_program(GLSL_VALIDATOR glslangValidator HINTS
        /usr/bin
        /usr/local/bin
        $ENV{VULKAN_SDK}/Bin/
        $ENV{VULKAN_SDK}/Bin32/)

message(STATUS "Compiling shaders...")
message(STATUS "Found program: ${GLSL_VALIDATOR}")

file(GLOB_RECURSE GLSL_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/shaders/*.frag"
        "${PROJECT_SOURCE_DIR}/shaders/*.vert")

message(STATUS "Source shader files: ${GLSL_SOURCE_FILES}")

foreach(GLSL ${GLSL_SOURCE_FILES})
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${PROJECT_SOURCE_DIR}/shaders/compiled_shaders/${FILE_NAME}.spv")
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

message(STATUS "Compiled binary: ${SPIRV_BINARY_FILES}")
message(STATUS "Shaders compiled...")

add_custom_target(
        shaders
        DEPENDS ${SPIRV_BINARY_FILES}
)