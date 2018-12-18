#include <iostream>
#include "Queue.h"

int main()
{
  TQueue<int> queue(10);
  int tmp;
  std::cout << "Queue is: ";
  if (queue.IsEmpty())
    std::cout << "empty.\n";
  else if (queue.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Filling the queue with values from 1 to 10... \n";
  for (int i = 0; i < 10; i++)
    queue.Put(i+1);
  std::cout << "Queue is: ";
  if (queue.IsEmpty())
    std::cout << "empty.\n";
  else if (queue.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";
  std::cout << "Getting element from queue...\n";
  tmp = queue.Get();
  std::cout << "Element from Queue equals: " << tmp << "\n";
  std::cout << "Queue is: ";
  if (queue.IsEmpty())
    std::cout << "empty.\n";
  else if (queue.IsFull())
    std::cout << "full.\n";
  else
    std::cout << "not empty and not full.\n";

  return 0;
}
