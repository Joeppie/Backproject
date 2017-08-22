
#include "util.h"
#include <stdexcept>
#include <iomanip>
#include<iostream>


/**
 * Constructor for the point struct, so that an easy way to construct it with the right values exists.
 * @param x x ordinate
 * @param y y ordinate
 */
Point::Point(double x, double y) : x(x), y(y)
{}

Point::Point()
{}


void clearScreen()
{
    if (system("CLS"))
    {
        system("clear");
    }
}

void sleep(double seconds){
    int msleep = static_cast<int>(seconds *1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(msleep));
}

void PressEnterToContinue()
{
    PressEnterToContinue(std::cout,std::cin);
}
void PressEnterToContinue(std::ostream &os,std::istream &is)
{
    os << "\nPress Enter to Continue..";
    os.flush();
    is.ignore(1000,'\n');
}




