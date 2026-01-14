#pragma once

#include <optional>
#include <vulkan/vulkan.h>

struct  QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    [[nodiscard]] bool isComplete() const;

    [[nodiscard]] uint32_t* data() const;
};

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR surface);