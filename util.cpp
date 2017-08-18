//
// Created by Joep on 18-8-2017.
//


#include "util.h"

void multiply(const matrix &a,const matrix &b,matrix& c) {
    for (int row = 0; row < a.size(); row++) {
        for (int col = 0; col < b[0].size(); col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < a[0].size(); inner++) {
                c[row][col] += a[row][inner] * b[inner][col];
            }
        }
    }
}


void printMatrix(const matrix& matrix)
{
    for(const auto &row : matrix)
    {
        for(const auto &value : row)
        {
            std::cout << " " << value;
        }
        std::cout << std::endl;
    }
}


template <size_t size_x, size_t size_y>
matrix arrayToMatrix(const double (&jaggedArray)[size_x][size_y])
{
    matrix matrix;
    for (int i = 0; i < size_x; ++i)
    {
        std::vector<double> row;
        for (int j = 0; j < size_y; ++j)
        {
            row.push_back(jaggedArray[i][j]);
        }
        matrix.push_back(row);
    }
    return matrix;
}
