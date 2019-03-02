#include <iostream>
#include "ArrList.h"

int main()
{
	TArrayList<int> arrlist(10);
	int tmp;
	try
	{
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Filling the ArrayList with values from 1 to 10... \n";
		for (int i = 0; i < 10; i++)
			arrlist.PutStart(i + 1);
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from end of ArrayList...\n";
		tmp = arrlist.GetEnd();
		std::cout << "Element from end of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from start of ArrayList...\n";
		tmp = arrlist.GetStart();
		std::cout << "Element from start of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Putting  25 to the 2nd index of ArrayList...\n";
		arrlist.Put(2, 25);
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from 2nd index of ArrayList...\n";
		tmp = arrlist.Get(2);
		std::cout << "Element from 2nd index of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
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