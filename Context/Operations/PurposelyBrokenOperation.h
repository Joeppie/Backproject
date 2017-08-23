#ifndef BACKPROJECT_PURPOSELYBROKENOPERATION_H
#define BACKPROJECT_PURPOSELYBROKENOPERATION_H


#include "ContextOperation.h"

/**
 * This operation's perform method is 66% likely to throw an exception.
 */
class PurposelyBrokenOperation : public ContextOperation {
public:
     bool IsPossible(const Context &context) const;
     std::string getDescription() const;
    /**
     * 33% of time, this method works every time. In 66% of times, it throws an exception.
     * @param context
     * @return a string expressing mild surprise at how the the method succeeded.
     */
     std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_PURPOSELYBROKENOPERATION_H
