//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_UTIL_H
#define BACKPROJECT_UTIL_H

#include <vector>
#include <array>
#include <iostream>

struct Point
{
    double x;

    Point(double x, double y);
    Point();

    double y;
};


//shorthand forms that are applicable to our application.
using matrix = std::vector<std::vector<double>>;
using vector = std::vector<double>;

/**
 * Multiplies two matrices to create a new one with the result of the mulitplication.
 * @param a right-hand side matrix
 * @param b left-hand size matrix
 */
matrix multiply(const matrix &a,const matrix &b);

void printMatrix(const matrix& matrix);


/**
 * swaps the sign on every value inside the matrix; e.g. a column with 1 becomes -1 and vice versa
 * @param a
 */
matrix negate(const matrix &a);

/**
 * 'Concatenates' a matrix b, to matrix A; this fills result matrix C with all rows and columns of A, and each row ends with the columns of B.
 * @param a original matrix
 * @param b matrix to concatenate with, number of rows must match A.
 */
matrix concatenate(const matrix &a,const matrix &b);

template <size_t size_x, size_t size_y>
matrix arrayToMatrix(const double (&jaggedArray)[size_x][size_y]);

/**
 * Reads a value of class T, and then returns the result, forcing the user to enter a correct value.
 * @tparam T
 * @param prompt The initial prompt asking the user to enter a value via std::cout.
 * @param tryAgain The message that shows when the user did not enter a valid value.
 * @return a valid value of T.
 */
template<class T>
T ReadAndValidate();

#include "util.hpp"


#endif //BACKPROJECT_UTIL_H
