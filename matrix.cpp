#define verbose_back_project

//
// Created by Joep on 22-8-2017.
//


#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include "matrix.h"


matrix multiply(const matrix &a, const matrix &b)
{

    if (a[0].size() != b.size())
    {
        throw std::invalid_argument(
                "Number of rows in the second matrix does not match number of columns in the first, multiplication is not possible.");
    }

    matrix c(a.size(), vector(b[0].size()));



    for (unsigned int row = 0; row < a.size(); row++)
    {
        for (unsigned int col = 0; col < b[0].size(); col++)
        {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (unsigned int inner = 0; inner < a[0].size(); inner++)
            {
                c[row][col] += a[row][inner] * b[inner][col];
            }
        }
    }
    return c;
}

matrix negate(const matrix &a)
{
    matrix result = a; //make a copy of A.
    for (vector &row : result)
    {
        for (auto &value : row)
        {
            value = -value;
        }
    }
    return result;
}

matrix transpose(const matrix &original)
{
    matrix transposed (original[0].size(), vector(original.size()));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            transposed[j][i] = original[i][j];
        }
    }
    return transposed;
}

matrix concatenate(const matrix &a, const matrix &b)
{
    //TODO: verify that the amount of rows in B is the same as in A, otherwise the operation is invalid to alert to programmer error.
    size_t columns = a[0].size();
    size_t newColumns = b[0].size();
    size_t rows = a.size();

    //the result matrix has as many rows as matrix A, with each row having as many columns as A and B combined.
    matrix c(rows, vector(columns + newColumns));

    //Loop over and perform for every row..
    for (unsigned int i = 0; i < rows; ++i)
    {
        //copy and append all coumns from A to C.
        for (unsigned int j = 0; j < columns; ++j)
        {
            c[i][j] = a[i][j];
        }
        //Copy and append to each row all columns from B to C.
        for (unsigned int k = 0; k < newColumns; ++k)
            for (unsigned int k = 0; k < newColumns; ++k)
            {
                c[i][k + columns] = b[i][k];
            }
    }
    return c;
}



void printMatrix(const matrix &matrix,const std::string &description)
{
#ifdef verbose_back_project
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        std::cout << "{empty matrix}" << std::endl;
        return;
    }

    const int seperatorwidth = 1;
    const int columnwidth = 16;
    const int barLength = columnwidth * matrix[0].size() +
                          seperatorwidth * (matrix[0].size() + 3);

    std::cout << description << ":" << std::endl;
    for (const auto &row : matrix)
    {
        std::cout << std::string(barLength, '-') << "\n"; //Seperator between rows or begin.
        std::cout << "|"; //begin of row
        for (const auto &value : row)
        {
            std::cout << " " << std::setw(columnwidth) << std::setprecision(3) << std::fixed << value;
            std::cout << "|"; //seperator or end of row.
        }
        std::cout << "\n";
    }
    std::cout << std::string(barLength, '-') << std::endl;

#endif
}