#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

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

  Player(){}

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

#endif
