#ifndef __GLSCENE_HPP__
#define __GLSCENE_HPP__

class GLScene
{
protected:
  int object_cnt;
  GLObject* objects[100];

public:
  GLScene()
  {
    object_cnt = 0;
    Start();
  }

  void Search(const char* name)
  {
    for (int idx = 0; idx < object_cnt; idx++)
    {
      //TBD...
    }
  }

  void AddScene(GLObject* obj)
  {
    objects[object_cnt] = obj;
    object_cnt++;
  }

  void Pop(GLObject* obj)
  {
    for (int idx = 0; idx < object_cnt; idx++)
    {
      if (obj == objects[idx])
      {
        GLObject *removeObj = objects[idx];
        delete removeObj;
        removeObj = NULL;
        object_cnt--;
      }
    }
  }

  virtual bool Render()
  {
    for (int idx = 0; idx < object_cnt; idx++)
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
    for (int idx = 0; idx < object_cnt; idx++)
    {
      delete objects[idx];
    }
  }
};
#endif