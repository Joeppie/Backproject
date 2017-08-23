//
// Created by Joep on 22-8-2017.
//

#ifndef BACKPROJECT_PURPOSELYBROKENOPERATION_H
#define BACKPROJECT_PURPOSELYBROKENOPERATION_H


#include "ContextOperation.h"

/**
 * This operation's perform method is 66% likely to throw an exception.
 */
class PurposelyBrokenOperation : public ContextOperation {
     bool IsPossible(const Context &context) const;
     std::string getDescription() const;
     std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_PURPOSELYBROKENOPERATION_H
