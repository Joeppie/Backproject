#include <iostream>
#include "util.h"
/*
#include"Classes/image.h"
#include"Classes/InteriorOrientation.h"
#include"Classes/ExteriorOrientation.h"
*/




int main()
{
    std::cout << "Hello, World!" << std::endl;


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

    printMatrix(c);

    return 0;
}