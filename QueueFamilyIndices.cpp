#include "QueueFamilyIndices.h"

#include <vector>

bool QueueFamilyIndices::isComplete() const {
    return graphicsFamily.has_value() &&
        presentFamily.has_value();
}

uint32_t* QueueFamilyIndices::data() const {
    if (!isComplete()) {
        return nullptr;
    }
    if (graphicsFamily.value() == presentFamily.value()) {
        return new uint32_t[] {
            graphicsFamily.value()
        };
    }
    return new uint32_t[] {
        graphicsFamily.value(),
        presentFamily.value()
    };
}

QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice device, const VkSurfaceKHR surface) {
    QueueFamilyIndices indices;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (indices.isComplete()) {
            break;
        }
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }
        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);
        if (presentSupport) {
            indices.presentFamily = i;
        }
        i++;
    }
    return indices;
}
