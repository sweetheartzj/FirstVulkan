cmake_minimum_required(VERSION 4.1)
project(FirstVulkan)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(FirstVulkan main.cpp
        Application.cpp
        Application.h
        QueueFamilyIndices.cpp
        QueueFamilyIndices.h
)

target_link_libraries(FirstVulkan PUBLIC glm::glm glfw Vulkan::Vulkan)
