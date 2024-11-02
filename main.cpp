#include <iostream>
#include "matrix.hpp"

int main()
{
  int m = 0;
  int n = 0;
  std::cout << "number of rows and columns\n";
  std::cin >> m >> n;
  if (!std::cin || m <= 0 || n <= 0)
  {
    std::cerr << "Invalid element\n";
    return 1;
  }
  Matrix matrix1(m, n);

  std::cout << "matrix 1 has been created\n";
  std::cout << "input of the first matrix\n";
  try
  {
    matrix1.inputMatrix();
  }
  catch (...)
  {
    std::cerr << "Invalid element\n";
    return 1;
  }
  std::cout << "output of the first matrix\n";
  matrix1.outputMatrix();

  std::cout << "changing the size of first matrices\n";
  std::cin >> m >> n;
  if (std::cin.fail() || m <= 0 || n <= 0)
  {
    std::cerr << "Invalid element\n";
    return 1;
  }
  matrix1.changeSizeMatrix(m,n);
  std::cout << "output of the first matrix\n";
  matrix1.outputMatrix();

  Matrix matrix2(matrix1);
  std::cout << "matrix 2 was created a copy of matrix 1\n";
  std::cout << "input 2 of the matrix\n";

  try
  {
    matrix2.inputMatrix();
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Invalid element\n";
    return 1;
  }

  std::cout << "output of the first matrix\n";
  matrix1.outputMatrix();

  std::cout << "output of the second matrix\n";
  matrix2.outputMatrix();

  return 0;
}
