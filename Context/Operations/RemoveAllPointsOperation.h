
#ifndef BACKPROJECT_REMOVEALLPOINTS_H
#define BACKPROJECT_REMOVEALLPOINTS_H


#include "ContextOperation.h"

/**
 * An operation that removes all the points on a context.
 */
class RemoveAllPointsOperation : public ContextOperation
{
public:
    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_REMOVEALLPOINTS_H
