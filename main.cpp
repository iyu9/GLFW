#ifdef WINDOWS
    #include <gl/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <iostream>

#include "GLShader.hpp"
#include "GLVec.hpp"
#include "GLUtils.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"

GLScene currentScene;
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
    
    GLObject *obj = new GLObject(pos, g_winSize);
    currentScene.Push(obj);
}

void MainLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);
        currentScene.Render();
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
