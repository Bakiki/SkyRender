#pragma once
#include <precomp.h>
#include<vulkan/vulkan.h>
#include <glfw_window.h>
#include <vector>

namespace sreng {

  class Graphics final{

  public:
    Graphics(gsl::not_null<Window*> window);
    ~Graphics();
  private:
    void InitializeVulkan();
    void CreateInstance();

    static gsl::span<gsl::czstring> GetSuggestedInstanceExtensions();
    static std::vector<VkExtensionProperties> GetSupportedInstanceExtensions();
    static bool AreAllExtensionsSupported(gsl::span<gsl::czstring> extrensions);
    static bool ExtensionMatchesName(gsl::czstring name, const VkExtensionProperties& properties);
    static bool IsExtensionSupported(gsl::span<VkExtensionProperties> extensions, gsl::czstring name);



    VkInstance instance_ = nullptr;
    gsl::not_null<Window*> window_;
  };

}
