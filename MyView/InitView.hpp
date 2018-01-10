#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

//Check GameLogic
#include "../GameLogic/Physics.hpp"
#include "../GameLogic/MessageWindow.hpp"

class InitView : public GLScene
{
private:
  GLObject* actor;
  GLObject* bg;

  BMP* bmp_bg;
  BMP* bmp_chara;

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

    bmp_bg = new BMP("Resources/sample.bmp");
    bmp_chara = new BMP("Resources/player.bmp");

    //add Background to scene
    GLVec2 pos_bg = { 0, 0 };
    GLVec2 siz_bg = { 2, 2 };

    bg = new GLObject(pos_bg, siz_bg);
    bg->SetTexture(bmp_bg->texture);
    Push(bg);

    //add Actor to scene
    GLVec2 pos_actor = { 0, 0 };
    GLVec2 siz_actor = { 1, 1 };

    actor = new GLObject(pos_actor, siz_actor);
    actor->SetTexture(bmp_chara->texture);
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
    delete bmp_chara;
  }
};

#endif
