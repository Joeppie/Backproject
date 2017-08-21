
#ifndef BACKPROJECT_REMOVEIMAGE_H
#define BACKPROJECT_REMOVEIMAGE_H

#include "ContextOperation.h"

/**
 * Removes one specific images from the context.
 */
class RemoveImageOperation : public ContextOperation
{

public:
    virtual bool IsPossible(const Context &context) const;

    virtual std::string getDescription() const;

    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_REMOVEIMAGE_H
