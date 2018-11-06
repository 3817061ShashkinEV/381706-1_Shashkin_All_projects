#include <iostream>
#include <TVector.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	char choice = 0;
	int numOfChange = 0;
	int scalarMultiplication = 0;
	int number;
	int element;
	int a[3] = { 1,2,3 };
	int b[3] = { 3,2,1 };
	TVector<int> vector1(3,a);
	TVector<int> vector2(3, b);
	TVector<int> vector3;
	TVector<int> vector4;
	std::cout << "Первый веткор: " << vector1 << "\n";
	std::cout << "Второй веткор: " << vector2 << "\n";
	std::cout << "Введите третий вектор. \n";
	std::cin >> vector3;
	std::cout << "Третий вектор: " << vector3 << "\n";
	std::cout << "-----------------------------------------------------------------------\n";
	try
	{
		std::cout << "Перегруженная операция сложения: \n";
		std::cout << "Первый веткор: " << vector1 << "\n";
		std::cout << "Второй веткор: " << vector2 << "\n";
		std::cout << "Сложение...\n";
		vector4 = vector1 + vector2;
		std::cout << "Четвертый вектор:" << vector4 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex)
	{
		std::cout << "Мы поймали ошибку: " << ex.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "Метод изменения размера вектора: \n";
		std::cout << "Третий веткор: " << vector3 << "\n";
		std::cout << "Введите величину изменения вектора: ";
		std::cin >> numOfChange;
		std::cout << "Введите '+' для увелечения размера вектора или '-' для его уменьшения: ";
		std::cin >> choice;
		switch (choice) 
		{
		case '+':
			vector3.ChangeLenOfVector(numOfChange, '+');
			break;
		case '-':
			vector3.ChangeLenOfVector(numOfChange, '-');
			break;
		default:
			vector3.ChangeLenOfVector(numOfChange, choice);
			break;
		}
		std::cout << "Третий веткор: " << vector3 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex1)
	{
		std::cout << "Мы поймали ошибку: " << ex1.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try
	{
		std::cout << "Перегруженная операция вычитания: \n";
		std::cout << "Первый веткор: " << vector1 << "\n";
		std::cout << "Второй веткор: " << vector2 << "\n";
		std::cout << "Вычитание...\n";
		vector4 = vector1 - vector2;
		std::cout << "Четвертый вектор:" << vector4 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex2)
	{
		std::cout << "Мы поймали ошибку: " << ex2.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "Перегруженная операция скалярного умножения: \n";
		std::cout << "Первый веткор: " << vector1 << "\n";
		std::cout << "Второй веткор: " << vector2 << "\n";
		std::cout << "Скалярное умножение...\n";
		scalarMultiplication = vector1*vector2;
		std::cout << "Скалярное произведение равно: " << scalarMultiplication << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex3)
	{
		std::cout << "Мы поймали ошибку: " << ex3.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	std::cout << "Перегруженная операция умножения на число: \n";
	std::cout << "Третий вектор: " << vector3 << "\n";
	std::cout << "Введите число: ";
	std::cin >> number;
	std::cout << "Умножение на число " << number << " ...\n";
	vector3*number;
	std::cout << "Третий вектор: " << vector3 << "\n";
	std::cout << "-----------------------------------------------------------------------\n";
	try 
	{
		std::cout << "Перегруженная операция деления на число: \n";
		std::cout << "Третий вектор: " << vector3 << "\n";
		std::cout << "Введите число: ";
		std::cin >> number;
		std::cout << "Деление на число " << number << " ...\n";
		vector3 / number;
		std::cout << "Третий вектор: " << vector3 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex4)
	{
		std::cout << "Мы поймали ошибку: " << ex4.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "Перегруженная операция доступа к элементам вектора на чтение: \n";
		std::cout << "Четвертый вектор:" << vector4 << "\n";
		std::cout << "Доступ к элементу...\n";
		element = vector4[0];
		std::cout << "Первый элемент вектора: " << element << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex5)
	{
		std::cout << "Мы поймали ошибку: " << ex5.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
}