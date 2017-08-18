#include <iostream>
#include "util.h"
/*
#include"Classes/image.h"
#include"Classes/InteriorOrientation.h"
#include"Classes/ExteriorOrientation.h"
*/






int main()
{
    int h;
    matrix obj_points; //Matrix containing the object points
    std::cout << "Welcome to a our simple Photogrammetry backprojection program \n";
    std::cout << "Do you want to run the program in demo mode [*.csv-files with object coordinates are loaded automatically] \n";
    std::cout << "or would you like to enter object coordinates manually? Press [1] for demo mode and [2] for manual mode\n";
    std::cin >> h;

    switch (h) {
        case 1: std::cout << "You selected demo mode \n";
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



    //Note: below is some example code, we should replace this by the menu structure that allows user input
    //e.g. print list of choices with numbers, and after entering number, go to corresponding input/output

    double identity[3][3] = {{1, 0, 0},
                            {0, 1, 0},
                            {0, 0, 1}};


//    matrix identityMatrix = arrayToMatrix(identity);
//    printMatrix(identityMatrix);

    //Todo just allocate, it is silly to crerate a completely filled array.
    double cr[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};

    matrix a = {{1,4},
                {2,5},
                {3,6}};

    //arrayToMatrix(ar);
    matrix b = {{7, 8, 9}
               ,{10, 11, 12}};

    matrix c(a.size(),std::vector<double>(b[0].size()));

    multiply(a,b,c);

    printMatrix(obj_points);

    return 0;
}