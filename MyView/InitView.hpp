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
      bmp = new BMP("../../Resources/sample.bmp");
    #else
      bmp = new BMP("Resources/sample.bmp");
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

    GLdouble deltaTime = g_timer.GetDelta();
    g_timer.Update();

    if (g_keyInput.GetKey(GLFW_KEY_RIGHT))
    {
      actor->pos.x += deltaTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_LEFT))
    {
      actor->pos.x -= deltaTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_UP))
    {
      actor->pos.y += deltaTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_DOWN))
    {
      actor->pos.y -= deltaTime;
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
