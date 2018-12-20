#include <iostream>
#include "Matrix.h"
#include <time.h>

int main()
{
  TMatrix<double>  matrix1(5), matrix2(5), matrix3(5);
  for(int i=0;i<5;i++)
    for (int j = 0; j < 5 - i; j++)
    {
      matrix1[i][j] = double(i) + 1.0;
      matrix2[i][j] = double(i) + 6.0;
    }
  std::cout << "First matrix: \n" << matrix1 << "\n";
  std::cout << "Second matrix: \n" << matrix2 << "\n";
  std::cout << "-----------------------------Matrix operations----------------------------------\n";

  try
  {
    matrix3 = matrix1 + matrix2;
    std::cout << "Result of addition of first matrix and second matrix: \n" << matrix3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    matrix3 = matrix2 - matrix1;
    std::cout << "Result of substraction of second matrix and first matrix: \n" << matrix3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    matrix3 = matrix1 * matrix2;
    std::cout << "Result of multiplication of first matrix and second matrix: \n" << matrix3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
  std::cout << "-----------------------------------------------------------------------\n";
  try
  {
    matrix3 = matrix1 / matrix2;
    std::cout << "Result of division of first matrix and second matrix: \n" << matrix3 << "\n";
  }
  catch (TMyException &ex)
  {
    ex.what();
  }
 
  /*std::cout << "-----------------------------input/output----------------------------------\n";
  TVector<int> matrix(5);
  std::cout << "Enter matrix with size equals 5: \n";
  std::cin >> matrix;
  std::cout << "\nMatrix entered by you: \n" << matrix << "\n";
  return 0;
  */
}