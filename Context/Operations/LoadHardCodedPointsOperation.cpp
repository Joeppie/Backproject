//
// Created by LijnenJJ on 21-8-2017.
//

#include "LoadHardCodedPointsOperation.h"

std::string LoadHardCodedPointsOperation::Perform(Context &context) const
{
    try
    {
        //Admittedly, not many points are loaded.
        vector coordinate = {91564.54, 438048.29, -8.73};
        context.addPoint(coordinate);

        return "Added hardcoded points to the context.";

    }
    catch (const std::exception &exception)
    {
        return "An error was encountered loading the images.";
    }
}

bool LoadHardCodedPointsOperation::IsPossible(const Context &context) const
{

    return true;
}

std::string LoadHardCodedPointsOperation::getDescription() const
{
    return "Load some hardcoded points";
}
