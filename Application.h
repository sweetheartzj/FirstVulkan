#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

class Application {
private:
    GLFWwindow* window{};

    VkInstance instance{};

public:
    void run();

private:
    void initWindow();

    void initVulkan();

    void mainLoop() const;

    void cleanup() const;

    void createInstance();
};
