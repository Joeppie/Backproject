//
// Created by joep on 8/20/17.
//

#include "LoadImagesFromCsv.h"
#include "../Context.h"
#include "../../ReadCSV.h"


std::string LoadImagesFromCsv::Perform(Context &context) const {
    try {
        std::string fileName;

        std::cout << "please enter the full filename of the csv containing the complete image metadata" << std::endl;
        std::cin >> fileName;
        //context.Images = ReadImageCsv(fileName);
    }
    catch(const std::exception &exception){
        std::cout << "An error was encountered loading the images." << std::endl;

    }
}

bool LoadImagesFromCsv::IsPossible(const Context &context) const {
    return false;
}

std::string LoadImagesFromCsv::getDescription() const{
    return "Load images from specific CSV file";
}
