#pragma once

#define GLFW_INCLUDE_VULKAN
#include <string>
#include <vector>
#include <GLFW/glfw3.h>

#include "QueueFamilyIndices.h"

constexpr int MAX_FRAMES_IN_FLIGHT = 2;

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
constexpr bool enableValidationLayers = false;
#else
constexpr bool enableValidationLayers = true;
#endif

class Application {
private:
    GLFWwindow* window{};

    VkInstance instance{};

    VkDebugUtilsMessengerEXT debugMessenger{};

    VkSurfaceKHR surface{};

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    QueueFamilyIndices queueFamilyIndices;

    VkDevice logicalDevice{};

    VkQueue graphicsQueue{};

    VkQueue presentQueue{};

    VkSwapchainKHR swapChain{};
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat{};
    VkExtent2D swapChainExtent{};

    std::vector<VkImageView> swapChainImageViews;

    VkRenderPass renderPass{};
    VkPipelineLayout pipelineLayout{};

    VkPipeline graphicsPipeline{};

    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkCommandPool commandPool{};

    std::vector<VkCommandBuffer> commandBuffers{};

    std::vector<VkSemaphore> imageAvailableSemaphores{};
    std::vector<VkSemaphore> renderFinishedSemaphores{};
    std::vector<VkFence> inFlightFences{};

    uint32_t currentFrame = 0;

    bool framebufferResized = false;

public:
    void run();

private:
    void initWindow();

    void initVulkan();

    void mainLoop();

    void cleanup() const;

    void createInstance();

    static bool checkValidationLayerSupport();

    static std::vector<const char*> getRequiredExtensions();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData
    );

    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void setupDebugMessenger();

    static VkResult createDebugUtilsMessengerEXT(
        VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger
    );

    static void destroyDebugUtilsMessengerEXT(
        VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator
    );

    void createSurface();

    void pickPhysicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device) const;

    void createLogicalDevice();

    static bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    void createSwapChain();

    void createImageViews();

    void createGraphicsPipeline();

    static std::vector<char> readFile(const std::string& filename);

    [[nodiscard]] VkShaderModule createShaderModule(const std::vector<char>& shaderCode) const;

    void createRenderPass();

    void createSwapChainFramebuffers();

    void createCommandPool();

    void createCommandBuffers();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex) const;

    void drawFrame();

    void createSyncObjects();

    void recreateSwapChain();

    void cleanupSwapChain() const;

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};
