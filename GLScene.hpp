#ifndef __GLSCENE_HPP__
#define __GLSCENE_HPP__

class GLScene
{
protected:
  int siz;
  GLObject* objects[100];

public:
  GLScene()
  {
    siz = 0;
    Start();
  }

  void Search(const char* name)
  {
    for (int idx = 0; idx < siz; idx++)
    {
      //TBD...
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

  virtual bool Render()
  {
    for (int idx = 0; idx < siz; idx++)
    {
      objects[idx]->Render();
    }

    Update();
    return false;
  }

  virtual void Start(){}
  virtual void Update(){}

  virtual void Release()
  {
    for (int idx = 0; idx < siz; idx++)
    {
      delete objects[idx];
    }
  }
};
#endif