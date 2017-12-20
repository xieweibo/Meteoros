#pragma once

#include "VulkanInstance.h"
#include "VulkanDevice.h"
#include <vector>
#include "Forward.h"
#include "Window.h"

class VulkanSwapChain 
{
    friend class VulkanDevice;

public:
    VkSwapchainKHR GetVulkanSwapChain() const;
    VkFormat GetVkImageFormat() const;
    VkExtent2D GetVkExtent() const;
    uint32_t GetIndex() const;
    uint32_t GetCount() const;
    VkImageView GetVkImageView(uint32_t index) const;
	VkImageView& GetRefVkImageView(uint32_t index);
	VkImage GetVkImage(uint32_t index) const;
    VkSemaphore GetImageAvailableVkSemaphore() const;
    VkSemaphore GetRenderFinishedVkSemaphore() const;

	void Create();
	void Recreate();
    void Acquire();
    void Present();
    ~VulkanSwapChain();

private:
    VulkanSwapChain(VulkanDevice* device, VkSurfaceKHR vkSurface);

    VulkanDevice* device;
    VkSurfaceKHR vkSurface;
    VkSwapchainKHR vkSwapChain;
    std::vector<VkImage> vkSwapChainImages;
    std::vector<VkImageView> vkSwapChainImageViews;
    VkFormat vkSwapChainImageFormat;
    VkExtent2D vkSwapChainExtent;
    uint32_t imageIndex = 0;

    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
};