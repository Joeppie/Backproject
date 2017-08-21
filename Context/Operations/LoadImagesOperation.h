

#ifndef BACKPROJECT_LOADIMAGESFROMCSV_H
#define BACKPROJECT_LOADIMAGESFROMCSV_H

#include <iostream>
#include "ContextOperation.h"

/**
 * Loads a set of images into the context by reading a CSV file.
 */
class LoadImagesOperation : public ContextOperation
{
public:

    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_LOADIMAGESFROMCSV_H
