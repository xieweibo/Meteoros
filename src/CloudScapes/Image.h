#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include "VulkanDevice.h"
#include "BufferUtils.h"
#include "Commands.h"
#include "Forward.h"

namespace Image
{
	void copyBufferToImage(VulkanDevice* device, VkCommandPool commandPool, VkBuffer buffer, VkImage& image, uint32_t width, uint32_t height);

	void copyBufferToImage3D(VulkanDevice* device, VkCommandPool commandPool, VkBuffer buffer, VkImage& image, uint32_t width, uint32_t height, uint32_t depth);

	void transitionImageLayout(VulkanDevice* device, VkCommandPool commandPool, VkImage& image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);

	void createImage(VulkanDevice* device, uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
		VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

	void createImageView(VulkanDevice* device, VkImageView& imageView, VkImage& textureImage,
		VkFormat format, VkImageAspectFlags aspectFlags);

	bool hasStencilComponent(VkFormat format);

	void createSampler(VulkanDevice* device, VkSampler& sampler, VkSamplerAddressMode addressMode, float maxAnisotropy);

	void setImageLayout(VkCommandBuffer cmdbuffer, VkImage image, VkImageAspectFlags aspectMask,
						VkImageLayout oldImageLayout, VkImageLayout newImageLayout);
}