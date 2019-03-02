#include <iostream>
#include "Polynom.h"

int main()
{
	int degrees1[] = { 1,2,3,4,5 };
	int degrees2[] = { 5,4,3,2,1 };
	int degrees3[] = { 6,0,7,9,8 };
	int degrees4[] = { 6,8,7,9,0 };
	try 
	{
		TMonom monom1(5, degrees1, 3.5);
		TMonom monom2(5, degrees2, 2.3);
		TMonom monom3(5, degrees3, 5.6);
		TMonom monom4(5, degrees4, 9.1);
		std::cout << "Monom 1: " << monom1 << ".\n";
		std::cout << "Monom 2: " << monom2 << ".\n";
		std::cout << "Monom 3: " << monom3 << ".\n";
		std::cout << "Monom 4: " << monom4 << ".\n";
		std::cout << "\n";
		TPolynom polynom1(5);
		TPolynom polynom2(5);
		TPolynom polynom3(5);
		polynom1 += monom1;
		polynom1 += monom3;
		polynom2 += monom2;
		polynom2 += monom4;
		std::cout << "Polynom 1 = Monom 1 + Monom 3: " << polynom1 << ".\n";
		std::cout << "\n";
		std::cout << "Polynom 2 = Monom 2 + Monom 4: " << polynom2 << ".\n";
		std::cout << "\n";
		polynom3 = polynom1 + polynom2;
		std::cout << "Polynom 1 + Polynom 2: " << polynom3 << ".\n";
		std::cout << "\n";
		polynom3 = polynom1 - polynom2;
		std::cout << "Polynom 1 - Polynom 2: " << polynom3 << ".\n";
		std::cout << "\n";
		polynom3 = polynom1 * polynom2;
		std::cout << "Polynom 1 * Polynom 2: " << polynom3 << ".\n";
	}

	catch (TMyException &ex)
	{
		ex.What();
	}
	return 0;
}