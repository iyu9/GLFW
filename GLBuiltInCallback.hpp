extern GLVec2 pos;

static void error_callback(int error, const char* description)
{
  std::cout << description;
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
