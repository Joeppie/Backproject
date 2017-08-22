
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
