#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

void deleteMatrix(int** t, size_t m);
void outputMatrix(const int * const * t, size_t m, size_t n);
void inputMatrix(const int * const * t, size_t m, size_t n);
int** createMatrix(size_t m, size_t n);

#endif
