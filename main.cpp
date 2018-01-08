#ifdef WIN32
  #pragma warning(disable : 4996) //ignore fopen_s warning
  #include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

//include My GL Classes
#include "GLVec.hpp"
#include "GLUtils.hpp"

#include "GLInput.hpp"
#include "GLObject.hpp"
#include "GLScene.hpp"
#include "GLShader.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"
#include "GLTimer.hpp"

//include My Classes
#include "GameLogic/Player.hpp"

//include My Scenes
#include "MyView/InitView.hpp"
#include "MyView/TitleView.hpp"
#include "MyView/ConfigView.hpp"
#include "MyView/MainView.hpp"

GLScene* currentScene;
const GLIntVec2 g_winSize = {300, 300};

void MessageWait()
{
  std::string str;
  std::cin >> str;
}

void MainLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);
    currentScene->Render();
  glFlush();
}

int main()
{
  if (!glfwInit())
  {
    std::cout << "init failed";
    MessageWait();
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "App", NULL, NULL);

  if (!window)
  {
    std::cout << "create window failed";
    MessageWait();
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);

  currentScene = new InitView();

  while (!glfwWindowShouldClose(window))
  {
    MainLoop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  delete currentScene;

  glfwTerminate();
  return 0;
}
