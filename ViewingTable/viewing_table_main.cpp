#include <iostream>
#include "ViewingTable.h"

int main()
{
	TTable<int> table(5);
	TElem<int> elem;
	table.Put("key1", 1);
	table.Put("key2", 3);
	table.Put("key3", 5);
	table.Put("key4", 7);
	table.Put("key5", 9);
	std::cout << "Searching element with key: \"key3\"...\n";
	elem = table.Search("key3");
	std::cout << "Key: " << elem.GetKey() << " | Data: " << elem.GetData() << "\n";
	std::cout << "---------------------------------------------------------------------------\n";
	std::cout << "Deleting element with key: \"key3\"...\n";
	table.Del("key3");
	std::cout << "---------------------------------------------------------------------------\n";
	std::cout << "Searching element with key: \"key3\"...\n";
	elem = table.Search("key3");
	std::cout << "Key: " << elem.GetKey() << " | Data: " << elem.GetData() << "\n";
	std::cout << "---------------------------------------------------------------------------\n";

	return 0;
}