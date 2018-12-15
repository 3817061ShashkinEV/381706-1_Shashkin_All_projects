#include <iostream>
#include "Vector.h"

int main()
{
  TVector<int> vector1(5), vector2(5), vector3(5);
  for (int i = 0; i < 5; i++)
  {
    vector1[i] = i + 1;
    vector2[i] = i + 6;
  }
  std::cout << "First vector: \n" << vector1 << "\n";
  std::cout << "Second vector: \n" << vector2 << "\n";
  std::cout << "-----------------------------Scalar operations----------------------------------\n";

  try 
  {
    vector3 = vector1 + 2;
    std::cout << "Result of addition of first vector and number \'2\': \n" << vector3 << "\n";
  }
  catch(TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    vector3 = vector2 - 2;
    std::cout << "Result of substraction of second vector and number \'2\': \n" << vector3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    vector3 = vector1 * 3;
    std::cout << "Result of multiplication of first vector and number \'3\': \n" << vector3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------Vector operations----------------------------------\n";

  try
  {
    vector3 = vector1 + vector2;
    std::cout << "Result of addition of first vector and second vector: \n" << vector3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    vector3 = vector1 - vector2;
    std::cout << "Result of substraction of first vector and second vector: \n" << vector3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    int tmp;
    tmp = vector1 * vector2;
    std::cout << "Result of scalar multiplication of first vector and second vector: " << tmp << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  /*
  std::cout << "-----------------------------input/output----------------------------------\n";
  TVector<int> vector(5);
  std::cout << "Enter vector with size equals 5: \n";
  std::cin >> vector;
  std::cout << "\nVector entered by you: \n" << vector << "\n";
	return 0;
  */
}
