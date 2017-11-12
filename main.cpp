#ifdef WINDOWS
    #include <gl/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <iostream>

#include "GLVec.hpp"
#include "GLShader.hpp"
#include "GLUtils.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"

GLScene sceneManager;
const GLVec2 g_winSize = {200, 200};

GLVec2 pos;
BMP *bmp;

//from GLShader.hpp
extern GLuint shader_program;

void CustomInit()
{
  GLUtils::CheckRenderTexture();
  CompileAndLinkShader();

  //bmp = new BMP("sample.bmp");
  //glBindTexture(GL_TEXTURE_2D, bmp->texture);
}

void MainLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);

  //2dTexture
  glColor3f(1, 1, 1);
  GLUtils::DrawTexture(-1.0f + pos.x, -1.0f + pos.y, 2.0f, 2.0f);
    
  //2dRect
  glColor3f(1, 1, 1);
  glUseProgram(shader_program);
    GLUtils::DrawRect(-0.25f + pos.x, -0.25f + pos.y, 0.5f, 0.5f);
  glUseProgram(0);
    
  glFlush();
}

int main()
{
  glfwSetErrorCallback(error_callback);
  if (!glfwInit())
  {
    std::cout << "init failed";
    return 1;
  }

  GLFWwindow *window =
    glfwCreateWindow(g_winSize.x, g_winSize.y, "SAMPLE", NULL, NULL);

  if (!window)
  {
    std::cout << "create window failed";
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

  glfwTerminate();
  return 0;
}
