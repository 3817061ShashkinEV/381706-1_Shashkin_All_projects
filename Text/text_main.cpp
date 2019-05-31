#include <iostream>
#include "Text.h"

int main()
{
  std::string str;
  str="Example string\n";
  TNode node(str);
  std::cout << "Creating text...\n";
  TText text;
  std::cout << "Add string into text...\n";
  text.Ins(text.GetRoot(), str);
  std::cout << "Result: " << text << "\n";
  std::cout << "Find index for ""str""\n";
  int tmp = text.FindIndex("str");
  std::cout << "Index: " << tmp << "\n";
	return 0;
}