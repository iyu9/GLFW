#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define LOG(X) std::cout << X
#define REP(X) for (int i = 0; i < X; i++)

std::string WaitInput()
{
  std::string input_str;
  std::cin >> input_str;
  return input_str;
}

#endif
