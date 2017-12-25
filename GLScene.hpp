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

  void Search(const char* name)
  {
    for (int idx = 0; idx < siz; idx++)
    {
      //TBD
    }
  }

  void Push(GLObject* obj)
  {
    objects[siz] = obj;
    siz++;
  }

  void Pop(GLObject* obj)
  {
    for (int idx = 0; idx < siz; idx++)
    {
      if (obj == objects[idx])
      {
        GLObject *removeObj = objects[idx];
        delete removeObj;
        removeObj = NULL;
        siz--;
      }
    }
  }

  bool Render()
  {
    for (int idx = 0; idx < siz; idx++)
    {
      objects[idx]->Render();
    }
    return false;
  }

  virtual void Start(){}
  virtual void Update(){}
};
#endif