#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__

const double GRV = 9.8;

namespace Direction
{
  const int UP    = 0;
  const int RIGHT = 1;
  const int LEFT  = 2;
  const int DOWN  = 3;
};

class Physics
{
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

  bool CheckFallStart()
  {
	if (!is_fall && y > 0 && vy == 0)
	{
	  t = 0;
	  is_fall = true;
	  return true;
	}
	return false;
  }

  bool CheckFallEnd()
  {
	if (is_fall && y == 0 && vy < 0)
	{
	  t = 0;
	  y = 0;
	  vy = 0;
	  is_fall = false;
	  return true;
	}
	return false;
  }

  void Fall(double deltaFrame)
  {
	if (is_fall)
	{
	  t += deltaFrame;
	  vy = vy - GRV * t;
	  y = y - vy * t;
	}
  }

  void Update(double deltaFrame)
  {
	CheckFallStart();
	Fall(deltaFrame);
	CheckFallEnd();
  }
};

#endif
