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
	std::cout << "������ ������: " << vector1 << "\n";
	std::cout << "������ ������: " << vector2 << "\n";
	std::cout << "������� ������ ������. \n";
	std::cin >> vector3;
	std::cout << "������ ������: " << vector3 << "\n";
	std::cout << "-----------------------------------------------------------------------\n";
	try
	{
		std::cout << "������������� �������� ��������: \n";
		std::cout << "������ ������: " << vector1 << "\n";
		std::cout << "������ ������: " << vector2 << "\n";
		std::cout << "��������...\n";
		vector4 = vector1 + vector2;
		std::cout << "��������� ������:" << vector4 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex)
	{
		std::cout << "�� ������� ������: " << ex.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "����� ��������� ������� �������: \n";
		std::cout << "������ ������: " << vector3 << "\n";
		std::cout << "������� �������� ��������� �������: ";
		std::cin >> numOfChange;
		std::cout << "������� '+' ��� ���������� ������� ������� ��� '-' ��� ��� ����������: ";
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
		std::cout << "������ ������: " << vector3 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex1)
	{
		std::cout << "�� ������� ������: " << ex1.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try
	{
		std::cout << "������������� �������� ���������: \n";
		std::cout << "������ ������: " << vector1 << "\n";
		std::cout << "������ ������: " << vector2 << "\n";
		std::cout << "���������...\n";
		vector4 = vector1 - vector2;
		std::cout << "��������� ������:" << vector4 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex2)
	{
		std::cout << "�� ������� ������: " << ex2.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "������������� �������� ���������� ���������: \n";
		std::cout << "������ ������: " << vector1 << "\n";
		std::cout << "������ ������: " << vector2 << "\n";
		std::cout << "��������� ���������...\n";
		scalarMultiplication = vector1*vector2;
		std::cout << "��������� ������������ �����: " << scalarMultiplication << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex3)
	{
		std::cout << "�� ������� ������: " << ex3.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	std::cout << "������������� �������� ��������� �� �����: \n";
	std::cout << "������ ������: " << vector3 << "\n";
	std::cout << "������� �����: ";
	std::cin >> number;
	std::cout << "��������� �� ����� " << number << " ...\n";
	vector3*number;
	std::cout << "������ ������: " << vector3 << "\n";
	std::cout << "-----------------------------------------------------------------------\n";
	try 
	{
		std::cout << "������������� �������� ������� �� �����: \n";
		std::cout << "������ ������: " << vector3 << "\n";
		std::cout << "������� �����: ";
		std::cin >> number;
		std::cout << "������� �� ����� " << number << " ...\n";
		vector3 / number;
		std::cout << "������ ������: " << vector3 << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex4)
	{
		std::cout << "�� ������� ������: " << ex4.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
	try 
	{
		std::cout << "������������� �������� ������� � ��������� ������� �� ������: \n";
		std::cout << "��������� ������:" << vector4 << "\n";
		std::cout << "������ � ��������...\n";
		element = vector4[0];
		std::cout << "������ ������� �������: " << element << "\n";
		std::cout << "-----------------------------------------------------------------------\n";
	}
	catch (TMyException &ex5)
	{
		std::cout << "�� ������� ������: " << ex5.what();
		std::cout << "-----------------------------------------------------------------------\n";
	}
}