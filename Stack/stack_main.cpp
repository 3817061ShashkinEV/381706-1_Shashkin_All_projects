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
  std::cout << "Filling the stack with values from 1 to 10... \n";
  for (int i = 0; i < 10; i++)
    stack.Put(i+1);
  std::cout << "Stack is: ";
  if (stack.IsEmpty())
    std::cout << "empty.\n";
  else if (stack.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Getting element from stack...\n";
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