#include <iostream>
#include <memory>
#include "util.h"
#include "ReadCSV.h"

#include "Context/Context.h"
#include "Context/Operations/ContextOperation.h"
#include "Context/Operations/LoadImagesOperation.h"

void testCallToBackProject()
{

    auto images = ReadImageCsv("dummy.csv"); //vector of shared ptr of images.

    std::cout << "Performing backprojection.." << "\n" << *(images[0]) << std::endl;

    vector coordinate = {91564.54, 438048.29, -8.73};    //Coordinate to backproject
    Point row_column;               //Result variable

    bool inside = images[0]->backProject(coordinate,row_column);

    std::string result = inside ? "inside the image" :  "sadly, not located in the image!";
    std::cout << "the point was " << result << std::endl;


}


int main()
{

    Context context;

    //register the load images operation.
    Context::registerOperation(std::shared_ptr<ContextOperation>(new LoadImagesOperation));


    std::cout << "context has " << context.listOperations().size() << "operations available." << std::endl;


    int h;
    matrix obj_points; //Matrix containing the object points
    std::cout << "Welcome to a our simple Photogrammetry backprojection program \n";
    std::cout << "Do you want to run the program in demo mode [*.csv-files with object coordinates are loaded automatically] \n";
    std::cout << "or would you like to enter object coordinates manually? Press [1] for demo mode and [2] for manual mode\n";
    std::cin >> h;

    switch (h) {
        case 1: std::cout << "You selected demo mode \n";
            //This is not the real demo, but it calls what code currently exists.
            testCallToBackProject();
            break;
        case 2: std::cout << "You selected manual mode \n";

            int numpoints;

            std::cout << "How many points would you like to enter? \n"; std::cin >> numpoints;
            //std::cout << "Please enter your points in the following format [X, Y, Z] \n";


            for (int i = 0; i < numpoints; ++i) {

                std::vector<double> row;

                std::cout << "Enter an X coordinate\n";
                double tempX;
                std::cin >> tempX;
                row.push_back(tempX);

                std::cout << "Enter a Y coordinate\n";
                double tempY;
                std::cin >> tempY;
                row.push_back(tempY);

                std::cout << "Enter a Z coordinate\n";
                double tempZ;
                std::cin >> tempZ;
                row.push_back(tempZ);

                obj_points.push_back(row);
            }

            break;


        default: std::cout << "Please enter either [1] or [2]. This program cannot make a decision for you. It is just as smart enough to multiply some matrices.  \n";
            break;

    }

    return 0;
}