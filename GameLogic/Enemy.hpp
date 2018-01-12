#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include <string>

class Enemy : public Actor
{
public:

  Enemy(){}
  Enemy(int id_, std::string name_)
  {
    id = id_;
    name = name_;
  }
};

#endif
