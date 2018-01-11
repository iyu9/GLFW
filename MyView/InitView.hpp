#ifndef __INITVIEW_HPP__
#define __INITVIEW_HPP__

//Use GameLogic
#include "../GameLogic/Player.hpp"
#include "../GameLogic/Physics.hpp"
#include "../GameLogic/MessageWindow.hpp"

class InitView : public GLScene
{
private:
  GLObject* bg;
  GLObject* player;
  GLObject* enemy1;
  GLObject* enemy2;

  BMP* bmp_bg;
  BMP* bmp_chara;

  Player playerInfo;
  Player enemyInfo;

  Physics physics;
  MessageWindow msgwindow;

  double frameTime;

public:
  InitView() : GLScene()
  {
    GLScene::Start();
    Start();
  }

  void Start() override
  {
    GLScene::Start();

    //bmp_bg = new BMP("Resources/sample.bmp");
    bmp_chara = new BMP("Resources/player.bmp");

    //add Background to scene
    /*
    GLVec2 pos_bg = { 0, 0 };
    GLVec2 siz_bg = { 2, 2 };

    bg = new GLObject(pos_bg, siz_bg);
    bg->SetTexture(bmp_bg->texture);
    Push(bg);
    */

    //add Actor to scene
    GLVec2 pos_actor = { 0, 0 };
    GLVec2 siz_actor = { 1, 1 };

    player = new GLObject(pos_actor, siz_actor);
    player->SetTexture(bmp_chara->texture);
    AddScene(player);

    //add Enemy1 to scene
    GLVec2 pos_enemy1 = { -1, 0 };
    GLVec2 siz_enemy1 = { 0.5, 0.5 };

    enemy1 = new GLObject(pos_enemy1, siz_enemy1);
    enemy1->SetTexture(bmp_chara->texture);
    AddScene(enemy1);

    //add Enemy2 to scene
    enemy2 = new GLObject(pos_enemy1, siz_enemy1);
    enemy2->SetTexture(bmp_chara->texture);
    AddScene(enemy2);
  }

  void Update() override
  {
    GLScene::Update();

    if (object_cnt <= 0)
    {
      return;
    }

    //for check log
    g_timer.Update();
    frameTime = g_timer.GetFrameTime();

    //player scrolled
    player->pos.y = (player->pos.y > 1) ? -1 : player->pos.y;
    player->pos.y = (player->pos.y < -1) ? 1 : player->pos.y;
    player->pos.x = (player->pos.x > 1) ? -1 : player->pos.x;
    player->pos.x = (player->pos.x < -1) ? 1 : player->pos.x;

    //enemies scrolled
    enemy1->pos.x = (enemy1->pos.x > 1) ? -1 : enemy1->pos.x + (2 * frameTime);
    enemy2->pos.y = (enemy2->pos.y > 1) ? -1 : enemy2->pos.y + (2 * frameTime);

    //physics gravity test
    physics.Update();
    std::cout << "(x, y) = " << "(" << physics.x << ", " << physics.y << ")" << std::endl;
    std::cout << "(vx, vy) = " << "(" << physics.vx << ", " << physics.vy << ")" << std::endl;
    player->pos.y = physics.y;

    UpdateKeysInput();
  }

  void UpdateKeysInput()
  {
    //directions
    if (g_keyInput.GetKey(GLFW_KEY_RIGHT))
    {
      player->pos.x += 2 * frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_LEFT))
    {
      player->pos.x -= 2 * frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_UP))
    {
      player->pos.y += 2 * frameTime;
    }
    if (g_keyInput.GetKey(GLFW_KEY_DOWN))
    {
      player->pos.y -= 2 * frameTime;
    }

    //actions
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

    delete player;
    delete enemy1;
    delete enemy2;

    delete bmp_chara;
  }
};

#endif
