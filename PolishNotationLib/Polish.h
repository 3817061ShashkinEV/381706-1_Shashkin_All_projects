#pragma once
#include "Queue.h"
#include "MyString.h"

bool IsOperation(char _op);
int GetPriority(const char _op);
TQueue<char> ConvertToPolishNotation(TMyString _str);
double Result(TQueue<char> _queue);
