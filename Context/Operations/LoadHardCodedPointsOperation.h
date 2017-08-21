//
// Created by LijnenJJ on 21-8-2017.
//

#ifndef BACKPROJECT_LOADHARDCODEDPOINTSOPERATION_H
#define BACKPROJECT_LOADHARDCODEDPOINTSOPERATION_H

#include<iostream>
#include "ContextOperation.h"
#include "../Context.h"


/**
 * Loads a hardcoded set of points into a context.
 */
class LoadHardCodedPointsOperation : public ContextOperation
{
public:

    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_LOADHARDCODEDPOINTSOPERATION_H
