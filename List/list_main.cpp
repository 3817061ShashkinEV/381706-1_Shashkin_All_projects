#include <iostream>
#include "List.h"
#include <time.h>

int main()
{
  TList<int> list;
  int tmp;
  std::cout << "List is: ";
  if (list.IsEmpty())
    std::cout << "empty.\n";
  else if (list.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Filling the list with values from 1 to 10... \n";
  for (int i = 0; i < 10; i++)
    list.PutBegin(i + 1);
  std::cout << "List is: ";
  if (list.IsEmpty())
    std::cout << "empty.\n";
  else if (list.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Getting element from end of list...\n";
  tmp = list.GetEnd();
  std::cout << "Element from end of list equals: " << tmp << "\n";
  std::cout << "List is: ";
  if (list.IsEmpty())
    std::cout << "empty.\n";
  else if (list.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Getting element from begin of list...\n";
  tmp = list.GetBegin();
  std::cout << "Element from begin of list equals: " << tmp << "\n";
  std::cout << "List is: ";
  if (list.IsEmpty())
    std::cout << "empty.\n";
  else if (list.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";

  return 0;
}