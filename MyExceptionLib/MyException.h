#pragma once
#include <iostream>

class TMyException :public std::exception
{
public:
  TMyException(char *msg) :exception(msg) {}
}; //TMyException
  