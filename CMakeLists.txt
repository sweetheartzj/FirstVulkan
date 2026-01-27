cmake_minimum_required(VERSION 4.1)
project(FirstVulkan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)
find_package(Stb REQUIRED)

add_executable(FirstVulkan main.cpp
        Application.cpp
        Application.h
        QueueFamilyIndices.cpp
        QueueFamilyIndices.h
        SwapChainSupportDetails.cpp
        SwapChainSupportDetails.h
        Vertex.h
        Vertex.cpp
        Descriptor.h
)

target_link_libraries(FirstVulkan PUBLIC glm::glm glfw Vulkan::Vulkan)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
