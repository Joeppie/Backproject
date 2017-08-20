//
// Created by joep on 8/20/17.
//

#ifndef BACKPROJECT_LOADIMAGESFROMCSV_H
#define BACKPROJECT_LOADIMAGESFROMCSV_H

#include <iostream>
#include "ContextOperation.h"

class LoadImagesFromCsv : public ContextOperation<LoadImagesFromCsv>{
public:

    virtual bool IsPossible(const Context &context) const;
    virtual std::string getDescription() const;
    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_LOADIMAGESFROMCSV_H
