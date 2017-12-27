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

#include "GLObject.hpp"
#include "GLScene.hpp"
#include "GLShader.hpp"
#include "GLBuiltInCallback.hpp"
#include "GLBmpLoader.hpp"

//for Entity Scene
#include "TitleView.hpp"
#include "MainView.hpp"

//from GLShader.hpp
extern GLuint shader_program;

GLScene currentScene;
const GLVec2 g_winSize = {300, 300};

GLVec2 pos;
BMP *bmp;

GLObject* obj1;
GLObject* obj2;
GLObject* obj3;
GLObject* obj4;

void CustomInit()
{
    GLUtils::CheckRenderTexture();
    CompileAndLinkShader();

#if WIN32
    bmp = new BMP("../../sample.bmp");
#else
    bmp = new BMP("sample.bmp");
#endif

    GLVec2 pos1 = {0.0, 0.0};
    GLVec2 siz1 = {1.0, 1.0};
    
    obj1 = new GLObject(pos1, siz1);
    obj1->SetTexture(bmp->texture);
    currentScene.Push(obj1);

    GLVec2 pos2 = {-1.0, -1.0};
    GLVec2 siz2 = {1.0, 1.0};
    
    obj2 = new GLObject(pos2, siz2);
    obj2->SetTexture(bmp->texture);
    currentScene.Push(obj2);

    GLVec2 pos3 = { -1.0, 0.0 };
    GLVec2 siz3 = { 1.0, 1.0 };

    obj3 = new GLObject(pos3, siz3);
    obj3->SetTexture(bmp->texture);
    currentScene.Push(obj3);

    GLVec2 pos4 = { 0.0, -1.0 };
    GLVec2 siz4 = { 1.0, 1.0 };

    obj4 = new GLObject(pos4, siz4);
    obj4->SetTexture(bmp->texture);
    currentScene.Push(obj4);
}

void CustomDelete()
{
    delete bmp;
    delete obj1;
    delete obj2;
    delete obj3;
    delete obj4;
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
  if (!glfwInit())
  {
    std::cout << "init failed";
    std::string str;
    std::cin >> str;
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "GLFW App", NULL, NULL);

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
