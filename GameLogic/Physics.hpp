#ifndef __PHYSICS_HPP__
#define __PHYSICS_HPP__

const double GRV = 9.8;

namespace Direction
{
  const int LEFT = 0;
  const int RIGHT = 1;
};

class Physics
{
public:
  bool is_fall;
  double t;
  double x, y;
  double vx, vy;
  double ax, ay;

  Physics(){}

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
	  is_fall = false;
	  return true;
	}
	return false;
  }

  void Fall()
  {
	if (is_fall)
	{
	  t += 0.001; //frametime
	  vy = vy - GRV * t;
	  y = y - vy * t;
	}
  }

  void Update()
  {
	float frameTime = 0.01f;

	CheckFallStart();
	Fall();
	CheckFallEnd();
  }
};

#ifdef UNIT_TEST
int main ()
{
  Physics p;
  return 0;  
}
#endif

#endif
