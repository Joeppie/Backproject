
#include <chrono>
#include <thread>
#ifndef BACKPROJECT_UTIL_H
#define BACKPROJECT_UTIL_H

#ifdef __cplusplus__
#include <cstdlib>
#else

#include <stdlib.h>

#endif

#include <vector>
#include <array>
#include <iostream>
#include <iomanip>

/**
 * Represents a 2 dimensional coordinate in an as yet unspecified unit (e.g. pixels or meters)
 */
struct Point
{
/**
 * the x ordinate of the point
 */
    double x;
    /**
     * the y ordinate of the point.
     */
    double y;

    /**
     * Creates an instance of a point assigning the x and y ordinates
     * @param x the x ordinate
     * @param y the y ordinate
     */
    Point(double x, double y);
    /**
     * the default constructor, necessary since a non-default constructor has been specified; the compiler won't generate this by itself,
     * and it would be very annoying if it were absent; since it would mean users would be forced to specify default values.
     */
    Point();


};


/**
 * represents a 2d matrix of double values using a std::vector<std::vector<double>>
 */
using matrix = std::vector<std::vector<double>>;
/**
 * represents a vector- or list- of double  values using a std::vector<double>
 */
using vector = std::vector<double>;

/**
 * Multiplies two matrices to create a new one with the result of the mulitplication.
 * @param a right-hand side matrix
 * @param b left-hand size matrix
 */
matrix multiply(const matrix &a, const matrix &b);

/**
 * Pretty-prints a matrix to the screen
 * @param matrix a matrix as represented by a std::vector<std::vector<double>>
 */
void printMatrix(const matrix &matrix);

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
matrix concatenate(const matrix &a, const matrix &b);

template<size_t size_x, size_t size_y>
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

/**
 * Clears the screen through an OS call.
 */
void clearScreen();

/**
 * Sleeps for the given amount of seconds.
 * @param seconds
 */
void sleep(double seconds);

/**
 * Method which uses std::cout and std::cin to ask the user to press the enter key, returns immediately afterward.
 */
void PressEnterToContinue();
/**
 * Method which uses the specified input and output stream to ask the user to press the enter key, returns immediately afterward.
 */
void PressEnterToContinue(std::ostream &os,std::istream &is);

#endif //BACKPROJECT_UTIL_H
