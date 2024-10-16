#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

int ** CreateMatrix(size_t m, size_t n);

void DeleteArray(int** t, size_t m, size_t n);

void in (int ** t, size_t m, size_t n);

#endif
