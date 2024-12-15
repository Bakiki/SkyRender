#include <GLFW/glfw3.h>
#include <glfw_initialization.h>
#include <glfw_monitor.h>



std::int32_t main()
{

  sreng::GlfwInitialization _glfw;

  gsl::not_null<GLFWwindow*> window = glfwCreateWindow(800,600, "Sky Render",nullptr,nullptr);
  gsl::final_action _cleanup_window([window] {glfwDestroyWindow(window); });

  gsl::span<GLFWmonitor*> monitors = sreng::GetMonitors();

  if (monitors.size() > 1) {
    sreng::MoveMonitorToWindow(window, monitors[1]);
  }
  else {
    sreng::MoveMonitorToWindow(window, monitors[0]);
  }

  
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

	return EXIT_SUCCESS;
}


