#include <GLFW/glfw3.h>
#include <glfw_initialization.h>
#include <glfw_monitor.h>
#include <glfw_window.h>
#include <precomp.h>



std::int32_t main()
{

  sreng::GlfwInitialization _glfw;
  sreng::Window window("Sky Render",{800,600});

  window.TryMoveToMonitors(1);
  
  while (!window.ShouldClose()) {
    glfwPollEvents();
  }

	return EXIT_SUCCESS;
}


