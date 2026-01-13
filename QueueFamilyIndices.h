#pragma once

#include <optional>
#include <vulkan/vulkan.h>

struct  QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    [[nodiscard]] bool isComplete() const;
};

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);