//
// Created by LijnenJJ on 21-8-2017.
//

#ifndef BACKPROJECT_REMOVEALLIMAGESOPERATION_H
#define BACKPROJECT_REMOVEALLIMAGESOPERATION_H


#include "ContextOperation.h"

/**
 * Removes all the images that a context has.
 */
class RemoveAllImagesOperation : public ContextOperation
{
public:
    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_REMOVEALLIMAGESOPERATION_H
