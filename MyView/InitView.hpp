#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

#include "../GameLogic/Physics.hpp"

class InitView : public GLScene
{
private:
  GLObject* actor;
  BMP* bmp;

  double deltaTime;
  Player plInfo;
  Physics phy;

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

    g_timer.Update();
    deltaTime = g_timer.GetDelta();

	//scrolled
	actor->pos.y = (actor->pos.y > 1) ? -1 : actor->pos.y;
	actor->pos.y = (actor->pos.y < -1) ? 1 : actor->pos.y;
	actor->pos.x = (actor->pos.x > 1) ? -1 : actor->pos.x;
	actor->pos.x = (actor->pos.x < -1) ? 1 : actor->pos.x;

	//physics test
	phy.y = 1;
	phy.Update();
	actor->pos.y = phy.y;

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
