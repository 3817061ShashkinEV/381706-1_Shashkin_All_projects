#include <iostream>
#include "MultiStack.h"
int main()
{
	try 
	{
		TMStack<int> multistack(2, 10);
		int k = 0;
		int tmp = 0;
		std::cout << "Filling the multistack with values from 1 to 10... \n";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
			{
				k++;
				multistack.SetElem(i, k);
			}
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(0))
			std::cout << "empty.\n";
		else if (multistack.IsFull(0))
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from first stack...\n";
		tmp = multistack.GetElem(0);
		std::cout << "Element from first stack equals: " << tmp << "\n";
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(0))
			std::cout << "empty.\n";
		else if (multistack.IsFull(0))
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Second stack is: ";
		if (multistack.IsEmpty(1))
			std::cout << "empty.\n";
		else if (multistack.IsFull(1))
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from second stack...\n";
		tmp = multistack.GetElem(1);
		std::cout << "Element from second stack equals: " << tmp << "\n";
		std::cout << "First stack is: ";
		if (multistack.IsEmpty(1))
			std::cout << "empty.\n";
		else if (multistack.IsFull(1))
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
	}

	catch (TMyException &ex)
	{
		ex.What();
	}
  return 0;
}