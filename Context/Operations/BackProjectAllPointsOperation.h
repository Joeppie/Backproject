

#ifndef BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H
#define BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H


#include "ContextOperation.h"

/**
 * this operation can backproject all points in a context to its images and display the result to the user.
 */
class BackProjectAllPointsOperation : public ContextOperation
{
    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_BACKPROJECTALLPOINTSOPERATION_H
