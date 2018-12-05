#include <iostream>
#include "Stack.h"

int main()
{
  TStack<int> stack(10);
  int tmp;
  std::cout << "Stack is: ";
  if (stack.IsEmpty())
    std::cout << "empty.\n";
  else if (stack.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  for (int i = 0; i < 10; i++)
    stack.Put(i);
  std::cout << "Stack is: ";
  if (stack.IsEmpty())
    std::cout << "empty.\n";
  else if (stack.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  tmp = stack.Get();
  std::cout << "Element from stack equals: " << tmp << "\n";
  std::cout << "Stack is: ";
  if (stack.IsEmpty())
    std::cout << "empty.\n";
  else if (stack.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";

  return 0;
}