#ifndef __GLSCENE_HPP__
#define __GLSCENE_HPP__

class GLScene
{
  int siz;
  GLObject* objects[100];

public:
  GLScene()
  {
    siz = 0;
  }

  void Push(GLObject* obj)
  {
    objects[siz] = obj;
    siz++;
  }

  void Pop()
  {
    objects[siz] = NULL;
    siz--;
  }

  bool Render()
  {
    for (int idx = 0; idx < siz; idx++)
    {
      objects[idx]->Render();
    }
    return false;
  }
};
#endif