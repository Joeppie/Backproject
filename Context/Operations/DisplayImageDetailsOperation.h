//
// Created by LijnenJJ on 21-8-2017.
//

#ifndef BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H
#define BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H


#include "ContextOperation.h"

class DisplayImageDetailsOperation : public ContextOperation
{
public:
    virtual bool IsPossible(const Context &context) const;
    virtual std::string getDescription() const;
    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H
