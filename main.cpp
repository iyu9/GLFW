//#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "GLVec.hpp"
#include "GLShader.hpp"
#include "GLUtils.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"

const int g_windowWidth = 200;
const int g_windowHeight = 200;

GLVec2 pos;
BMP *bmp;

//GLSLより
extern GLuint shader_program;

void CustomInit()
{
  //GLUtils::CheckRenderTexture();
  //CompileAndLinkShader();

  bmp = new BMP("sample.bmp");
  glBindTexture(GL_TEXTURE_2D, bmp->texture);
}

void MainLoop()
{
  glClear(GL_COLOR_BUFFER_BIT);

  //2dRect
  //glUseProgram(shader_program);
  //glColor3f(1, 1, 1);
  //GLUtils::DrawRect(-0.25f + pos.x, -0.25f + pos.y, 0.5f, 0.5f);
  //glUseProgram(0);

  //2dTexture
  glColor3f(1, 1, 1);
  GLUtils::DrawTexture(-0.8f + pos.x, -0.8f + pos.y, 1.6f, 1.6f);
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
    glfwCreateWindow(g_windowWidth, g_windowHeight, "SAMPLE", NULL, NULL);

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
