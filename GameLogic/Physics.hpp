#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__

namespace PhysicsDef
{
  const double GRV    = 0.001;
  const double N = 0.05;

  const double WALL_L = -1;
  const double WALL_R = 1;
  const double FLOOR  = -1;
  const double JUMP_V = 10;

  const double ADD_VELOCITY = 0.01;
};
using namespace PhysicsDef;

namespace Dir2D
{
  const int UP    = 0x001;
  const int RIGHT = 0x002;
  const int LEFT  = 0x004;
  const int DOWN  = 0x008;
};
using namespace Dir2D;

class Physics
{
private:
  void CheckFall()
  {
    //Start falling
    if (!is_fall && y > FLOOR)
    {
      t = 0;
      is_fall = true;
    }

    //Finish falling
    if (y <= FLOOR)
    {
      t = 0; vy = 0;
      y = FLOOR;
      is_fall = false;
    }
  }

  void UpdateMoving()
  {
    if (vy != 0)
    {
      vy -= GRV;
      y += vy;
    }

    if (vx != 0)
    {
      vx *= (1 - N);
      x += vx;
    }
  }

public:
  bool is_fall;
  bool is_jump;

  double t;
  double x, y;
  double vx, vy;
  double ax, ay;

  Physics()
  {
    is_fall = false;
    is_jump = false;
  }

  void Jump()
  {
    vy = JUMP_V;
    is_jump = true;
  }

  void AddVelocity(const int dir)
  {
    switch (dir)
    {
    case UP:
      vy = ADD_VELOCITY;
      break;
    case DOWN:
      vy = -ADD_VELOCITY;
      break;
    case LEFT:
      vx = -ADD_VELOCITY;
      break;
    case RIGHT:
      vx = ADD_VELOCITY;
      break;
    }
  }

  void Update()
  {
    CheckFall();
    UpdateMoving();
  }
};

#endif
