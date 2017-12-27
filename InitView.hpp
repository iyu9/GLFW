#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

class InitView : public GLScene
{
private:
  GLObject* actor;
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

    actor = new GLObject(pos1, siz1);
    actor->SetTexture(bmp->texture);
    Push(actor);
  }

  void Update() override
  {
    GLScene::Update();

    if (siz <= 0) { return; }

    //input sample
    if (g_keyInput.GetKey(GLFW_KEY_RIGHT))
    {
      actor->pos.x += 0.01;
    }
    if (g_keyInput.GetKey(GLFW_KEY_LEFT))
    {
      actor->pos.x -= 0.01;
    }
    if (g_keyInput.GetKey(GLFW_KEY_UP))
    {
      actor->pos.y += 0.01;
    }
    if (g_keyInput.GetKey(GLFW_KEY_DOWN))
    {
      actor->pos.y -= 0.01;
    }
  }

  void Release() override
  {
    GLScene::Release();

    delete actor;
    delete bmp;
  }
};

#endif
