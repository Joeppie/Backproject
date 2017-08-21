#include <iostream>
#include <memory>
#include "util.h"
#include "ReadCSV.h"

#include "Context/Context.h"
#include "Context/Operations/ContextOperation.h"
#include "Context/Operations/LoadImagesOperation.h"
#include "Context/Operations/LoadHardCodedPointsOperation.h"
#include "Context/Operations/RemoveImageOperation.h"
#include "Context/Operations/RemoveAllImagesOperation.h"
#include "Context/Operations/RemoveAllPointsOperation.h"
#include "Context/Operations/BackProjectAllPointsOperation.h"

void testCallToBackProject()
{

    auto images = ReadImageCsv("dummy.csv"); //vector of shared ptr of images.

    std::cout << "Performing backprojection.." << "\n" << *(images[0]) << std::endl;

    vector coordinate = {91564.54, 438048.29, -8.73};    //Coordinate to backproject
    Point row_column;               //Result variable

    bool inside = images[0]->backProject(coordinate, row_column);

    std::string result = inside ? "inside the image" : "sadly, not located in the image!";
    std::cout << "the point was " << result << std::endl;


}


int main()
{

    Context context;

    //register the load images operation.
    Context::registerOperation(std::shared_ptr<ContextOperation>(new LoadImagesOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new LoadHardCodedPointsOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new BackProjectAllPointsOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveImageOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveAllImagesOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveAllPointsOperation));


    context.Enter(std::cout, std::cin);
    return 0;
}