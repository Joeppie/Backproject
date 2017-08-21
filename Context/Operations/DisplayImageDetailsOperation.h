
#ifndef BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H
#define BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H


#include "ContextOperation.h"

/**
 * This operation allows the user to inspect details regarding the images that are loaded into the context currently.
 */
class DisplayImageDetailsOperation : public ContextOperation
{
public:
    virtual bool IsPossible(const Context &context) const;
    virtual std::string getDescription() const;
    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_DISPLAYIMAGEDETAILSOPERATION_H
