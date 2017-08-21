

#include <sstream>
#include "EnterPointsOperation.h"


bool EnterPointsOperation::IsPossible(const Context &context) const
{
    return true; //There are no preconditions.
}
std::string EnterPointsOperation::getDescription() const
{
    return "Enter points manually";
}
std::string EnterPointsOperation::Perform(Context &context) const
{
    int count = 0;
    char yesOrNo;
    //'endless' loop that terminates when a non y/Y character is entered in response to the question posed below.
    for(;;)
    {
        std::cout << "Would you like to add " << (count==0 ? "a point" : "another point") << "y/n?" << std::endl;
        yesOrNo  = ReadAndValidate<char>(); //Read a single char

        if(yesOrNo == 'y' || yesOrNo == 'Y')
        {
            count++;
            std::vector<double> point;

            //Get values for x,y,z and store them in that order into the point vector, before adding to context.
            for (char ordinate = 'x'; ordinate <= 'z'; ++ordinate) {
                std::cout << "please enter value for " << ordinate << ":" << std::endl;
                point.push_back(ReadAndValidate<double>());
            }
          context.addPoint(point);
        }
        else
        {
            std::stringstream format;
            format << "Added " << count << " new points";
            return format.str();
        }
    }
}