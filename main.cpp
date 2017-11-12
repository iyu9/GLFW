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

    bmp = new BMP("sample.bmp");
    
    GLVec2 pos1 = {0.0, 0.0};
    GLVec2 siz1 = {1.0, 1.0};
    
    GLObject *obj1 = new GLObject(pos1, siz1);
    currentScene.Push(obj1);

    GLVec2 pos2 = {-1.0, -1.0};
    GLVec2 siz2 = {1.0, 1.0};
    
    GLObject *obj2 = new GLObject(pos2, siz2);
    obj2->SetTexture(bmp->texture);
    currentScene.Push(obj2);
}

void CustomDelete()
{
    delete bmp;
}


void MainLoop()
{
    glClear(GL_COLOR_BUFFER_BIT);
        glColor3d(1, 1, 1);
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

  CustomDelete();

  glfwTerminate();
  return 0;
}
