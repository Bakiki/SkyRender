#include <glfw_initialization.h>
#include <GLFW/glfw3.h>
#include <precomp.h>

namespace sreng {

  GlfwInitialization::GlfwInitialization() {
    if (glfwInit() != GLFW_TRUE) {
      std::exit(EXIT_FAILURE);
    }
  }

  GlfwInitialization::~GlfwInitialization(){
    glfwTerminate();
  }
}
