#include <iostream>
#include "Polish.h"

int main()
{
  try {
    std::cout << "Math expression: (45+55)/10-5*5 = ";
    char buf[] = "(45+55)/10-5*5";
    TMyString str(buf);
    TQueue<char> queue;
    queue = ConvertToPolishNotation(str);
    std::cout << Result(queue) << ".\n";
  }

  catch (TMyException &ex)
  {
    ex.What();
  }
	return 0;
}