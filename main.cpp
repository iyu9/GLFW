#ifdef WIN32
  #include <GL/glew.h>
#endif

//---------------------------------------
// Note: File Path Setting:
//  Windows: ../../<FILE>
//  Mac: ./<FILE>
//---------------------------------------

//Ignore fopen warning
#pragma warning(disable : 4996) 
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

//for GL Custom Components
#include "GLVec.hpp"
#include "GLUtils.hpp"

#include "GLInput.hpp"
#include "GLObject.hpp"
#include "GLScene.hpp"
#include "GLShader.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"
#include "GLTimer.hpp"

//for include Real Scenes
#include "MyView/InitView.hpp"
#include "MyView/TitleView.hpp"
#include "MyView/ConfigView.hpp"
#include "MyView/MainView.hpp"

//from GLShader.hpp
extern GLuint shader_program;

GLScene* currentScene;
const GLIntVec2 g_winSize = { 300, 300 };

void CustomInit()
{
  currentScene = new InitView();
}

void CustomDelete()
{
  delete currentScene;
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
    std::string str;
    std::cin >> str;
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "App", NULL, NULL);

  if (!window)
  {
    std::cout << "create window failed";
    std::string str;
    std::cin >> str;
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);

  CustomInit();

  while (!glfwWindowShouldClose(window))
  {
    MainLoop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  CustomDelete();

  glfwTerminate();
  return 0;
}
