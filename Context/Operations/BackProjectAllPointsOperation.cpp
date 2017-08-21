//
// Created by LijnenJJ on 21-8-2017.
//

#include "BackProjectAllPointsOperation.h"
#include "../Context.h"
#include <iostream>
#include <sstream>

bool BackProjectAllPointsOperation::IsPossible(const Context &context) const
{

    return context.listImages().size() > 0 && context.listPoints().size() > 0;
}

std::string BackProjectAllPointsOperation::getDescription() const
{
    return "Back-project all 3d points into images";
}

std::string BackProjectAllPointsOperation::Perform(Context &context) const
{
    //Project all the points in all the images.
    //Use a stringstream to collect results whether points are visible in images, and if so, where.
    std::stringstream output;

    for (auto point : context.listPoints())
    {
        output << "point {" << point[0] << "," << point[1] << "," << point[2] << "}\n";
        for (auto image : context.listImages())
        {
            Point pixelCoordinates;
            bool insideImage = image->backProject(point, pixelCoordinates);
            if (insideImage)
            {
                output << "is visible in image    " << image->get_fileName() << " at pixel ("
                       << pixelCoordinates.x << "," << pixelCoordinates.y << ")\n";
            }
            else
            {
                output << "is not visible in image " << image->get_fileName() << "\n";
            }
        }
    }

    return output.str();
}