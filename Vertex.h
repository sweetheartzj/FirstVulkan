#pragma once

#include <glm/glm.hpp>
#include <vulkan/vulkan.h>


struct  Vertex {
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 texCoord;

    static VkVertexInputBindingDescription getBindingDescription();

    static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();
};

