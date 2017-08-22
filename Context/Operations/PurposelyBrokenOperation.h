//
// Created by Joep on 22-8-2017.
//

#ifndef BACKPROJECT_PURPOSELYBROKENOPERATION_H
#define BACKPROJECT_PURPOSELYBROKENOPERATION_H


#include "ContextOperation.h"

class PurposelyBrokenOperation : public ContextOperation {
     bool IsPossible(const Context &context) const;
     std::string getDescription() const;
     std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_PURPOSELYBROKENOPERATION_H