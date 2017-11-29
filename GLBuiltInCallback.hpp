#ifndef __GLBUILTINCALLBACK_HPP__
#define __GLBUILTINCALLBACK_HPP__

extern GLVec2 pos;

static void error_callback(int error, const char* description)
{
  std::cout << "error_description = " << description << std::endl;
  std::cout << "error_code = " << error << std::endl;

  switch (error)
  {
  case GLFW_NOT_INITIALIZED:
    std::cout << "GLFW_NOT_INITIALIZED";
    break;

  case GLFW_NO_CURRENT_CONTEXT:
    std::cout << "GLFW_NO_CURRENT_CONTEXT";
    break;

  case GLFW_INVALID_ENUM:
    std::cout << "GLFW_INVALID_ENUM";
    break;

  case GLFW_INVALID_VALUE:
    std::cout << "GLFW_INVALID_VALUE";
    break;

  case GLFW_OUT_OF_MEMORY:
    std::cout << "GLFW_OUT_OF_MEMORY";
    break;

  case GLFW_API_UNAVAILABLE:
    std::cout << "GLFW_API_UNAVAILABLE";
    break;

  case GLFW_VERSION_UNAVAILABLE:
    std::cout << "GLFW_VERSION_UNAVAILABLE";
    break;

  case GLFW_PLATFORM_ERROR:
    std::cout << "GLFW_PLATFORM_ERROR";
    break;

  case GLFW_FORMAT_UNAVAILABLE:
    std::cout << "GLFW_FORMAT_UNAVAILABLE";
    break;
  }

  //Wait
  std::string inputStr;
  std::cin >> inputStr;  
}

static void cursor_pos_callback(GLFWwindow* window, double x, double y)
{
  //std::cout << x << "," << y << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scanmode, int action, int mods)
{
  //Special Keys
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  //Default Keys
  if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.x -= 0.01f;
  }
  if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.x += 0.01f;
  }
  if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.y -= 0.01f;
  }
  if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.y += 0.01f;
  }

  //Default Keys
  if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.x -= 0.01f;
  }
  if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.x += 0.01f;
  }
  if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.y -= 0.01f;
  }
  if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
  {
    pos.y += 0.01f;
  }
}

#endif
