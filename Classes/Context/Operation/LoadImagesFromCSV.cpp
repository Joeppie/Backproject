//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_LOADIMAGESFROMCSV_H
#define BACKPROJECT_LOADIMAGESFROMCSV_H


#include "ContextOperation.h"
#include "../../../ReadCSV.h"

class LoadImagesFromCSV : public ContextOperation {

public:
    virtual bool IsPossible(const Context& context) const {
        return true; //The more, the merrier.
    }

 virtual std::string Perform(Context &context) {
        try {
            std::string fileName;

            std::cout << "please enter the full filename of the csv containing the complete image metadata" << std::endl;
            std::cin >> fileName;
            context.Images = ReadImageCsv(fileName);
        }
        catch(const std::exception &exception){
            std::cout << "An error was encountered loading the images." << std::endl;

        }
    }
}r;


#endif //BACKPROJECT_LOADIMAGESFROMCSV_H
