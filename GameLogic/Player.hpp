#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#define PLAYER_LIST_MAX 5

class Status
{
public:
  int lv;
  int lv_max;
  int hp;
  int hp_max;
  int mp;
  int max_mp;
  int cond;

  int atk_max;
  int def_max;
  int spd_max;
  int luk_max;
  int mov_max;

  int atk;
  int def;
  int spd;
  int luk;
  int mov;
};

class Equipment
{
public:
  int weapon;
  int shield;
  int armor;
  int helmet;
  int accesary;
};

class Skill
{
public:
  int id;
  int atk;
};

class Player
{
public:
  int id;
  std::string name;
  Status status;
  Equipment equipment;
  int x, y;

  Player(){}
  Player(int id_, std::string name_)
  {
    id = id_;
    name = name_;
  }
};

class PlayerList
{
public:
  Player players[PLAYER_LIST_MAX];
  int siz;

  PlayerList(int siz_)
  {
    siz = siz_;
  }

  bool Push(Player player)
  {
    players[siz++] = player;
    return true;
  }

  bool Pop()
  {
    siz--;
    return true;
  }
};

#endif
