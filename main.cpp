#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t m = 0, n = 0;
  std::cin >> m >> n;
  int **matrix = nullptr;
try {
    matrix = createMatrix(m, n);
  } catch (const std::bad_alloc & e) {
    std::cerr << "Out of memory\n";
    return 1;
  }
  inputMatrix(matrix,m,n);
  outputMatrix(matrix,m,n);
  deleteMatrix(matrix,m);

  return 0;
}
