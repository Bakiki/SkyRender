cmake_minimum_required(VERSION 3.22)
project(SkyRender)

find_package(Vulkan REQUIRED)

include(FetchContent)



#OpenGL Mathematics Library for graphics software based on the OpenGL Shading Language
FetchContent_Declare(
	glm
	GIT_REPOSITORY "https://github.com/g-truc/glm.git"
	GIT_TAG "0.9.9.8"
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glm)

file(GLOB_RECURSE SkyRenderSources CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

#GLFW is an Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development. 
#It provides a simple, platform-independent API for creating windows, 
#contexts and surfaces, reading input, handling events, etc.
FetchContent_Declare(
	glfw
	GIT_REPOSITORY "https://github.com/glfw/glfw.git"
	GIT_TAG "3.3.8"
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(glfw)

#GSL Microsoft's implementation of the C++ Core Guidelines Support Library (GSL)!
FetchContent_Declare(
	microsoft-gsl
	GIT_REPOSITORY "https://github.com/microsoft/GSL.git"
	GIT_TAG "v4.0.0"
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(microsoft-gsl)

#add_executable(SkyRender ${SkyRenderSources} "src/graphics.h" "src/graphics.cpp" "src/utilities.cpp")

target_link_libraries(SkyRender PRIVATE Vulkan::Vulkan)
target_link_libraries(SkyRender PRIVATE glm)
target_link_libraries(SkyRender PRIVATE glfw)
target_link_libraries(SkyRender PRIVATE Microsoft.GSL::GSL)

target_include_directories(SkyRender PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_features(SkyRender PRIVATE cxx_std_20)

target_precompile_headers(SkyRender PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/precomp.h")