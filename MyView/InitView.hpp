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
  GLObject* font;

  BMP* bmp_bg;
  BMP* bmp_chara;
  BMP* bmp_font;

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

  void SetFont()
  {
    font = new GLObject({ 0, 0 }, {1, 1});
    font->Set2DTexture(bmp_font->texture, {0.07, 0.78}, {0.1, 0.22});
    AddScene(font);
  }

  void Start() override
  {
    GLScene::Start();

    bmp_bg = new BMP("Resources/sample.bmp");
    bmp_chara = new BMP("Resources/player.bmp");
    //bmp_font = new BMP("Resources/font.bmp");

    //add Background to scene
    GLVec2 pos_bg = { 0, 0 };
    GLVec2 siz_bg = { 2, 2 };

    bg = new GLObject(pos_bg, siz_bg);
    bg->Set2DTexture(bmp_bg->texture);
    AddScene(bg);

    //add Actor to scene
    GLVec2 pos_actor = { 0, 0 };
    GLVec2 siz_actor = { 0.5, 0.5 };

    player = new GLObject(pos_actor, siz_actor);
    player->Set2DTexture(bmp_chara->texture);
    //player->Set3DCube();
    AddScene(player);

    //add Enemy1 to scene
    GLVec2 pos_enemy1 = { -1, 0 };
    GLVec2 siz_enemy1 = { 0.5, 0.5 };

    enemy1 = new GLObject(pos_enemy1, siz_enemy1);
    enemy1->Set2DTexture(bmp_chara->texture);
    AddScene(enemy1);

    //add Enemy2 to scene
    enemy2 = new GLObject(pos_enemy1, siz_enemy1);
    enemy2->Set2DTexture(bmp_chara->texture);
    AddScene(enemy2);

    //add font to scene
    //SetFont();
  }

  void Update() override
  {
    GLScene::Update();

    if (objects.size() <= 0)
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
    if (g_keyInput.GetKey(GLFW_KEY_SPACE))
    {
      physics.Jump();
    }

    //check rotation and translate
    if (g_keyInput.GetKey(GLFW_KEY_W))
    {
      glRotatef(1, 0, 1, 0);
    }
    if (g_keyInput.GetKey(GLFW_KEY_A))
    {
      glRotatef(1, 1, 0, 0);
    }
    if (g_keyInput.GetKey(GLFW_KEY_S))
    {
      glRotatef(-1, 0, 1, 0);
    }
    if (g_keyInput.GetKey(GLFW_KEY_D))
    {
      glRotatef(-1, 1, 0, 0);
    }
    if (g_keyInput.GetKey(GLFW_KEY_Q))
    {
      glRotatef(1, 0, 0, 1);
    }
    if (g_keyInput.GetKey(GLFW_KEY_E))
    {
      glRotatef(1, 0, 0, -1);
    }
    if (g_keyInput.GetKey(GLFW_KEY_O))
    {
      glTranslatef(0, 0, 1);
    }
    if (g_keyInput.GetKey(GLFW_KEY_P))
    {
      glTranslatef(0, 0, -1);
    }
  }

  void Release() override
  {
    GLScene::Release();

	delete bg;
    delete player;
    delete enemy1;
    delete enemy2;
    delete font;

    delete bmp_bg;
    delete bmp_chara;
    delete bmp_font;
  }
};

#endif
