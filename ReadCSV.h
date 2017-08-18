//
// Created by Joep on 18-8-2017.
//

#ifndef BACKPROJECT_READCSV_H
#define BACKPROJECT_READCSV_H


#include "Classes/Image.h"

/***
 * Reads a CSV file that describes Images, including with their interior and exterior orientation, to allow for backprojection of realworld coordinates.
 * @param fileName the relative or absolute path where the file is found.
 * @return a list of shared pointer classes of the Image class.
 */
std::vector<std::shared_ptr<Image>> ReadImageCsv(std::string fileName);

#endif //BACKPROJECT_READCSV_H
