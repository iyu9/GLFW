#ifndef __GLINPUT_HPP__
#define __GLINPUT_HPP__

class GLInput
{
private:
  GLint keyState[GLFW_KEY_LAST];
  int currentState;

  GLdouble mouse_x, mouse_y;

public:
  GLInput()
  {
    for (int idx = 0; idx < GLFW_KEY_LAST; idx++)
    {
      keyState[idx] = GLFW_RELEASE;
    }
  }

  void ScanKeyState(GLint key, GLint action)
  {
    keyState[key] = action;
  }

  void ScanMouseState(GLdouble x, GLdouble y)
  {
    mouse_x = x; mouse_y = y;
  }

  bool GetKey(GLint key)
  {
    return (keyState[key] == GLFW_PRESS || keyState[key] == GLFW_REPEAT);
  }

  bool GetKeyDown(GLint key)
  {
    return (keyState[key] == GLFW_PRESS);
  }

  bool GetKeyUp(GLint key)
  {
    //TBD...
    return (keyState[key] == GLFW_PRESS);
  }

  bool GetKeyRepeat(GLint key)
  {
    return (keyState[key] == GLFW_REPEAT);
  }
};

GLInput g_keyInput;

#endif
