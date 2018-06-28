#define RUN_ALL
#ifdef RUN_ALL

#ifdef WIN32
  #include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include "Common/Common.hpp"

//include My GL Classes
#include "GLComponents/GLComponents.hpp"

//include My Scenes
#include "MyView/InitView.hpp"
#include "MyView/TitleView.hpp"
#include "MyView/ConfigView.hpp"
#include "MyView/MainView.hpp"

GLScene* currentScene;
const GLIntVec2 g_winSize = {300, 300};
const GLIntVec2 g_winPos  = {1300, 640};

int main()
{
  if (!glfwInit())
  {
    LOG("init failed");
    WaitInput();
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "App", NULL, NULL);

  if (!window)
  {
    LOG("create window failed");
    WaitInput();
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
    glClear(GL_COLOR_BUFFER_BIT);
      currentScene->Render();
    glFlush();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  delete currentScene;

  glfwTerminate();
  return 0;
}

#endif

#ifdef UNITTEST_MIN_GLFW
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
  if (!glfwInit())
  {
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(680, 480, "Minimal_GLFW3_RunCheck", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

#endif

#ifdef UNITTEST_MIN_LIBPNG

#include "libpng/zlib.h"
#include "libpng/png.h"
#include <memory.h>
#include <iostream>

int main()
{
  const char filename[] = "test.png";

  png_image image;
  memset(&image, 0, sizeof(image));
  image.version = PNG_IMAGE_VERSION;

  std::cout << "Try to load: " << filename << std::endl;
  if (png_image_begin_read_from_file(&image, filename) != NULL)
  {
    std::cout << "png: w=" << image.width 
      << " h=" << image.height << std::endl;
  }
  else
  {
    std::cout << "ERROR: " << std::endl;
    if (PNG_IMAGE_FAILED(image))
    {
      std::cout << image.message << std::endl;
    }
  }

  // 読み出した情報に合わせて、データ部を格納するバッファを確保
  png_uint_32 stride = PNG_IMAGE_ROW_STRIDE(image);
  png_uint_16* buffer = new png_uint_16[PNG_IMAGE_BUFFER_SIZE(image, stride)];

  delete buffer;
  png_image_free(&image);

  int temp;
  std::cin >> temp;
  return 0;
}
#endif
