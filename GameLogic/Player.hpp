#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#define PLAYER_LIST_MAX 9

class Status
{
public:
  int lv;
  int hp;
  int hp_max;
  int mp;
  int max_mp;
  int cond;

  int atk;
  int def;
  int spd;
  int luk;
};

class Player
{
public:
  int id;
  char* name;
  Status status;
  int x, y;

  Player(){}
  Player(int id_, char* name_)
  {
    id = id_;
    name = name_;
  }

  int GetId()
  {
    return id;
  }

  const char* GetName()
  {
    return name;
  }

  Status GetStatus()
  {
    return status;
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
