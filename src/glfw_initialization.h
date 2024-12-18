#include <precomp.h>

namespace sreng{

struct GlfwInitialization {
public:
  GlfwInitialization();
  ~GlfwInitialization();

  GlfwInitialization(const GlfwInitialization&) = delete;
  GlfwInitialization& operator = (const GlfwInitialization&) = delete;
};
} //namespace sreng
