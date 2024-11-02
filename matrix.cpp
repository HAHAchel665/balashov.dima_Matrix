#include "matrix.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(int column, int row)
{
    this->column = column;
    this->row = row;
    matrix = createMatrix();
}

Matrix::Matrix(Matrix &other)
{
    this->column = other.column;
    this->row = other.row;
    this->matrix = createMatrix();

    for (size_t i = 0; i < column; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

int Matrix::getColumn() const
{
    return column;
}

int Matrix::getRow() const
{
    return row;
}

void Matrix::inputMatrix()
{
    for (size_t i = 0; i < column; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            std::cin >> matrix[i][j];
            if(!std::cin)
            {
              throw;
            }
        }
    }
}

Matrix::~Matrix()
{
    deleteMatrix();
}

void Matrix::outputMatrix() const
{
    for (size_t i = 0; i < column; i++)
    {
        std::cout << matrix[i][0];
        for (size_t j = 1; j < row; j++)
        {
            std::cout << " " << matrix[i][j];
        }
        std::cout << "\n";
    }
}

void Matrix::changeSizeMatrix(size_t newColumn, size_t newRow)
{
    int** newMartix = nullptr;
    newMartix = createMatrix(newMartix,newColumn, newRow);

    for (size_t i = 0; i < newColumn; i++)
    {
        if (i >= column)
        {
            for (size_t j = 0; j < newRow; j++)
            {
                newMartix[i][j] = 0;
            }
        }
        else
        {
            for (size_t j = 0; j < newRow; j++)
            {
                if (j >= row)
                {
                    newMartix[i][j] = 0;
                }
                else
                {
                    newMartix[i][j] = matrix[i][j];
                }
            }
        }
    }
    matrix = newMartix;
    row = newRow;
    column = newColumn;
}

void Matrix::deleteMatrix() const
{
    for (size_t i = 0; i < column; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::deleteMatrix(int**matrix, int column)
{
    for (size_t i = 0; i < column; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** Matrix::createMatrix()
{
    int** t = new int* [column];
    size_t created = 0;
    try
    {
        for (; created < column; ++created) 
        {
            t[created] = new int[row];
        }
    }
    catch (const std::bad_alloc& e)
    {
        deleteMatrix();
        throw;
    }
    return t;
}


int** Matrix::createMatrix(int**t,int column, int row)
{
    t = new int* [column];
    size_t created = 0;
    try
    {
        for (; created < column; ++created)
        {
            t[created] = new int[row];
        }
    }
    catch (const std::bad_alloc& e)
    {
        deleteMatrix(t, column);
        throw;
    }
    return t;
}
