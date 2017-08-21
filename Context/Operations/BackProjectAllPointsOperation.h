//
// Created by LijnenJJ on 21-8-2017.
//

#ifndef BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H
#define BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H


#include "ContextOperation.h"

class BackProjectAllPointsOperation : public ContextOperation
{
    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H
