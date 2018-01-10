#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

//Check GameLogic
#include "../GameLogic/Physics.hpp"
#include "../GameLogic/MessageWindow.hpp"

class InitView : public GLScene
{
private:
  GLObject* actor;
  BMP* bmp;

  double frameTime;
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

    bmp = new BMP("Resources/player.bmp");

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

    //for check log
    g_timer.Update();
    frameTime = g_timer.GetFrameTime();

    //scrolled
    actor->pos.y = (actor->pos.y > 1) ? -1 : actor->pos.y;
    actor->pos.y = (actor->pos.y < -1) ? 1 : actor->pos.y;
    actor->pos.x = (actor->pos.x > 1) ? -1 : actor->pos.x;
    actor->pos.x = (actor->pos.x < -1) ? 1 : actor->pos.x;

    //physics test
    physics.Update();
    std::cout << "(x, y) = " << "(" << physics.x << ", " << physics.y << ")" << std::endl;
    std::cout << "(vx, vy) = " << "(" << physics.vx << ", " << physics.vy << ")" << std::endl;
    actor->pos.y = physics.y;
    //std::cout << "(pos.x, pos.y) = " << "(" << actor->pos.x << ", " << actor->pos.y << ")" << std::endl;

    UpdateKeysInput();
  }

  void UpdateKeysInput()
  {
    //directions
    if (g_keyInput.GetKey(GLFW_KEY_RIGHT))
    {
      actor->pos.x += frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_LEFT))
    {
      actor->pos.x -= frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_UP))
    {
      actor->pos.y += frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_DOWN))
    {
      actor->pos.y -= frameTime;
    }

    //keys
    if (g_keyInput.GetKey(GLFW_KEY_Z))
    {
      physics.Jump();
    }
    if (g_keyInput.GetKey(GLFW_KEY_X))
    {
      physics.AddVelocity(Dir2D::LEFT);
    }
    if (g_keyInput.GetKey(GLFW_KEY_C))
    {
      physics.AddVelocity(Dir2D::DOWN);
    }
    if (g_keyInput.GetKey(GLFW_KEY_V))
    {
      physics.AddVelocity(Dir2D::RIGHT);
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
