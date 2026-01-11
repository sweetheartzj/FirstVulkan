#include "Application.h"

void Application::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Application::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

void Application::initVulkan() {
}

void Application::mainLoop() const {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void Application::cleanup() const {
    glfwDestroyWindow(window);
    glfwTerminate();
}
