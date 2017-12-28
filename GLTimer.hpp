#ifndef __GLTIMER_HPP__
#define __GLTIMER_HPP__

class GLTimer
{
private:
  GLdouble prevGetTime;
  GLdouble deltaTime;

public:
  GLTimer()
  {
    prevGetTime = glfwGetTime();
  }

  void Update()
  {
    GLdouble currentGetTime = glfwGetTime();
    deltaTime = currentGetTime - prevGetTime;

    prevGetTime = glfwGetTime();
  }

  GLdouble GetDelta()
  {
    return deltaTime;
  }

  GLdouble GetTime()
  {
    return glfwGetTime();
  }
};

GLTimer g_timer;
#endif
