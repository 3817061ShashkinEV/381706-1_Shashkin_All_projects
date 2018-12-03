#pragma once
#include <iostream>
#include <string>

class TMyException
{
private:
  std::string str;
public:
  TMyException(std::string _str);
  void what();
}; //TMyException
// ---------------------------------------------------------------------------
TMyException::TMyException(std::string _str) :str(_str) {};
// ---------------------------------------------------------------------------
void TMyException::what()
{
  std::cout << str << "\n";
}
  