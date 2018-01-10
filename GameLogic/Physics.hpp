#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__

namespace PhysicsDef
{
  const double GRV = 0.001;
  const double FLOOR = -1000000;
  const double JUMP_VY = 0.001;
};

namespace Direction2D
{
  const int UP = 0;
  const int RIGHT = 1;
  const int LEFT = 2;
  const int DOWN = 3;
};

using namespace PhysicsDef;

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
      t = 0; y = FLOOR; vy = 0;
      is_fall = false;
    }
  }

  void Fall(double deltaFrame)
  {
    if (is_fall)
    {
      t += deltaFrame;
      vy -= GRV * t;
      y += vy * t;
    }
  }

public:
  bool is_fall;

  double t;
  double x, y;
  double vx, vy;
  double ax, ay;

  Physics()
  {
    is_fall = false;
  }

  void Jump()
  {
    vy = PhysicsDef::JUMP_VY;
  }

  void Update(double deltaFrame)
  {
    CheckFall();
    Fall(deltaFrame);
  }
};

#endif
