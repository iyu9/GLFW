#ifndef __MENU_HPP__
#define __MENU_HPP__

#define MENU_MAX 9

#include <string>

class Menu
{
public:
  int idx;
  int siz;
  std::string menues[MENU_MAX];
  void* callback[MENU_MAX];

  Menu(int siz_)
  {
    siz = siz_;
  }

  void Next()
  {
    idx = (idx + 1 >= siz) ? 0 : idx++;
  }

  void Prev()
  {
    idx = (idx - 1 < 0) ? siz : idx--;
  }

  std::string GetName()
  {
    return menues[idx];
  }

  void OnClickMenu()
  {
    //hogehoge
  }
};

#endif
