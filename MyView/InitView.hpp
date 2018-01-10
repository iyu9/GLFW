#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

//TEST
#include "../GameLogic/Physics.hpp"
#include "../GameLogic/MessageWindow.hpp"

class InitView : public GLScene
{
private:
  GLObject* actor;
  BMP* bmp;

  double deltaTime;
  Player player;
  Physics physics;

public:
  InitView() : GLScene()
  {
    GLScene::Start();
    Start();
  }

  void Start() override
  {
    GLScene::Start();

    bmp = new BMP("Resources/sample.bmp");

    GLVec2 pos1 = { 0, 0 };
    GLVec2 siz1 = { 1, 1 };

    actor = new GLObject(pos1, siz1);
    actor->SetTexture(bmp->texture);
    Push(actor);
  }

  void Update() override
  {
    GLScene::Update();

    if (siz <= 0) { return; }

    g_timer.Update();
    deltaTime = g_timer.GetDelta();

    //scrolled
    actor->pos.y = (actor->pos.y > 1) ? -1 : actor->pos.y;
    actor->pos.y = (actor->pos.y < -1) ? 1 : actor->pos.y;
    actor->pos.x = (actor->pos.x > 1) ? -1 : actor->pos.x;
    actor->pos.x = (actor->pos.x < -1) ? 1 : actor->pos.x;

    //physics test
    physics.Update(deltaTime);
    std::cout << "phy.x, phy.y = " << physics.x << ", " << physics.y << std::endl;
    //std::cout << "(pos.x, pos.y) = " << "(" << actor->pos.x << ", " << actor->pos.y << ")" << std::endl;

    UpdateKeysInput();
  }

  void UpdateKeysInput()
  {
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
