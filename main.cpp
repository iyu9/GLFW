#ifdef WIN32
  #pragma warning(disable : 4996) //ignore fopen_s warning
  #include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "Common/common.hpp"

//include My GL Classes
#include "GLComponents/GLVec.hpp"
#include "GLComponents/GLUtils.hpp"

#include "GLComponents/GLInput.hpp"
#include "GLComponents/GLObject.hpp"
#include "GLComponents/GLScene.hpp"
#include "GLComponents/GLShader.hpp"
#include "GLComponents/GLBuiltInCallback.hpp"
#include "GLComponents/GLBmpLoader.hpp"
#include "GLComponents/GLTimer.hpp"

//include My Scenes
#include "MyView/InitView.hpp"
#include "MyView/TitleView.hpp"
#include "MyView/ConfigView.hpp"
#include "MyView/MainView.hpp"

GLScene* currentScene;
const GLIntVec2 g_winSize = {300, 300};
const GLIntVec2 g_winPos  = {720, 420};

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
    LOG("init failed");
    MessageWait();
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "App", NULL, NULL);

  if (!window)
  {
    LOG("create window failed");
    MessageWait();
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);
  glfwSetWindowPos(window, g_winPos.x, g_winPos.y);

  currentScene = new InitView();

  while (!glfwWindowShouldClose(window))
  {
    MainLoop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  //delete currentScene;

  glfwTerminate();
  return 0;
}
