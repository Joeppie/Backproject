//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_UTIL_H
#define BACKPROJECT_UTIL_H

#include <vector>
#include <array>
#include <iostream>

template<class T>
struct Point2
{
    T x;
    T y;
};

template<class T>
struct Point3
{
    T x;
    T y;
    T z;
};

//shorthand forms that are applicable to our application.
using matrix = std::vector<std::vector<double>>;
using vector = std::vector<double>;

/**
 * Multiplies two matrices to create a product.
 * @param a right-hand side matrix
 * @param b left-hand size matrix
 * @param c the resultant product matrix.
 */
void multiply(const matrix &a,const matrix &b,matrix& c);

void printMatrix(const matrix& matrix);

template <size_t size_x, size_t size_y>
matrix arrayToMatrix(const double (&jaggedArray)[size_x][size_y]);




#endif //BACKPROJECT_UTIL_H
