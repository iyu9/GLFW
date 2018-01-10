#ifndef __GLTIMER_HPP__
#define __GLTIMER_HPP__

class GLTimer
{
private:
  GLdouble prevGetTime;
  GLdouble frameTime;

public:
  GLTimer()
  {
    prevGetTime = glfwGetTime();
  }

  void Update()
  {
    GLdouble currentGetTime = glfwGetTime();
    frameTime = currentGetTime - prevGetTime;

    prevGetTime = glfwGetTime();
  }

  GLdouble GetFrameTime()
  {
    return frameTime;
  }

  GLdouble GetTime()
  {
    return glfwGetTime();
  }
};

GLTimer g_timer;
#endif
