#ifndef __GRIDMAP_HPP__
#define __GRIDMAP_HPP__

#define MAX_MAP_W 99
#define MAX_MAP_H 99

//map tip type
const int WALL = -1;
const int NONE = 0;
const int UP_STAIRS = 1;
const int DW_STAIRS = 2;

class GridMap
{
public:
  int id;
  char* name;
  IntVector2 siz;
  IntVector2 pos;
  int map[MAX_MAP_W][MAX_MAP_H];

  void CleanMap()
  {
	for (int j = 0; j < siz.y; j++)
	{
	  for (int i = 0; i < siz.x; i++)
	  {
	    map[i][j] = 0;
	  }  
	}
  }

  GridMap(int siz_x, int siz_y, int pos_x, int pos_y)
  {
	siz.x = siz_x; siz.y = siz_y;
	pos.x = pos_x; pos.y = pos_y;

	ClearMap();
  }
};

#endif
