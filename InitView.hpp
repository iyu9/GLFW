#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

class InitView : public GLScene
{
private:
  GLObject* obj1;
  BMP* bmp;

public:
  InitView() : GLScene()
  {
    GLScene::Start();
    Start();
  }

  void Start() override
  {
    GLScene::Start();

    #if WIN32
      bmp = new BMP("../../sample.bmp");
    #else
      bmp = new BMP("sample.bmp");
    #endif

    GLVec2 pos1 = { -0.5, -0.5 };
    GLVec2 siz1 = { 1.0, 1.0 };

    obj1 = new GLObject(pos1, siz1);
    obj1->SetTexture(bmp->texture);
    Push(obj1);
  }

  void Update() override
  {
    GLScene::Update();

    if (siz <= 0) { return; }
    obj1->pos.x += 0.01;

    if (obj1->pos.x > 1) { obj1->pos.x = -2; }
    if (obj1->pos.y > 1) { obj1->pos.y = -1; }
  }

  void Release() override
  {
    GLScene::Release();

    delete obj1;
    delete bmp;
  }
};

#endif
