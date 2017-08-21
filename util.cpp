//
// Created by Joep on 18-8-2017.
//


#include "util.h"
#include <stdexcept>
#include <iomanip>

matrix multiply(const matrix &a,const matrix &b) {

    if(a[0].size() != b.size())
    {
        throw std::invalid_argument( "Number of rows in the second matrix does not match number of columns in the first, multiplication is not possible." );
    }

    matrix c(a.size(),vector(b[0].size()));


    //todo: VERIFY that matrix A and B can even be multiplied; the amount of rows in B should be equal to the amount of columns in A.
    for (int row = 0; row < a.size(); row++) {
        for (int col = 0; col < b[0].size(); col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < a[0].size(); inner++) {
                c[row][col] += a[row][inner] * b[inner][col];
            }
        }
    }
    return c;
}

matrix negate(const matrix &a) {
    matrix result =a; //make a copy of A.
    for(vector& row : result)
    {
        for (auto &value : row)
        {
            value =-value;
        }
    }
    return result;
}

matrix concatenate(const matrix &a,const matrix &b)
{
    //TODO: verify that the amount of rows in B is the same as in A, otherwise the operation is invalid.
    size_t columns = a[0].size();
    size_t newColumns = b[0].size();
    size_t rows = a.size();

    //the result matrix has as many rows as matrix A, with each row having as many columns as A and B combined.
    matrix c (rows,vector(columns+newColumns));

    //Loop over and perform for every row..
    for (int i = 0; i <rows ; ++i)
    {
        //copy and append all coumns from A to C.
        for (int j = 0; j < columns ; ++j)
        {
            c[i][j] = a[i][j];
        }
        //Copy and append to each row all columns from B to C.
        for (int k = 0; k < newColumns; ++k)
        {
            c[i][k+columns] = b[i][k];
        }
    }
    return c;
}


void printMatrix(const matrix& matrix)
{
    if(matrix.size() == 0 ||  matrix[0].size() == 0)
    {
        std::cout << "{empty matrix}" << std::endl;
        return;
    }

    const int seperatorwidth = 1;
    const int columnwidth = 10;
    const int barLength = columnwidth * matrix[0].size() +
                            seperatorwidth * (matrix[0].size()+3);


    for(const auto &row : matrix)
    {
        std::cout << std::string(barLength,'-') << "\n"; //Seperator between rows or begin.
        std::cout << "|"; //begin of row
        for(const auto &value : row)
        {
            std::cout << " " << std::setw(columnwidth) << std::setprecision(3) << std::fixed << value;
            std::cout << "|"; //seperator or end of row.
        }
        std::cout << "\n";
    }
    std::cout << std::string(barLength,'-') << std::endl;


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

/**
 * Constructor for the point struct, so that an easy way to construct it with the right values exists.
 * @param x x ordinate
 * @param y y ordinate
 */
Point::Point(double x, double y) : x(x), y(y)
{}

Point::Point()
{}


template<class T>
T ReadAndValidate() {
    T n;
    std::cout << "enter value:";
    std::cout.flush();
    std::cin >> n;

    while (std::cin.fail() == 1 || n < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n'); //throw away 1000 chars, or next end of line
        std::cout << "\nincorrect value, please enter correct value";
        std::cin >> n;
    }
   // std::cout << "\n entered: " << n << std::endl;
    return n;
}