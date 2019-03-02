#include <iostream>
#include "StackList.h"

int main()
{
	try {
		TStackList<int> stacklist(10);
		int tmp;
		std::cout << "Stack is: ";
		if (stacklist.IsEmpty())
			std::cout << "empty.\n";
		else if (stacklist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Filling the stack with values from 1 to 10... \n";
		for (int i = 0; i < 10; i++)
			stacklist.Put(i + 1);
		std::cout << "Stack is: ";
		if (stacklist.IsEmpty())
			std::cout << "empty.\n";
		else if (stacklist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from stack...\n";
		tmp = stacklist.Get();
		std::cout << "Element from stack equals: " << tmp << "\n";
		std::cout << "Stack is: ";
		if (stacklist.IsEmpty())
			std::cout << "empty.\n";
		else if (stacklist.IsFull())
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