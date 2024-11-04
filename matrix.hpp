#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

class Matrix
{
private:
  int** matrix = 0;
  size_t column = 0;
  size_t row = 0;

  void deleteMatrix() const;
  void deleteMatrix(int** matrix, int column);
  int** createMatrix();
  int** createMatrix(int **t,int column, int row);

public:

  Matrix(int column, int row);
  Matrix(Matrix &other);
  ~Matrix();

  int getColumn() const;
  int getRow() const;

  void changeSizeMatrix(size_t column, size_t n);
  void outputMatrix() const;
  void inputMatrix() const;
};

#endif
