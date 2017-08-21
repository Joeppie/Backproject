//
// Created by Joep on 21-8-2017.
//

#ifndef BACKPROJECT_REMOVEIMAGE_H
#define BACKPROJECT_REMOVEIMAGE_H

#include "ContextOperation.h"


class RemoveImageOperation : ContextOperation {

public:
    virtual bool IsPossible(const Context &context) const;
    virtual std::string getDescription() const;
    virtual std::string Perform(Context &context) const;

};


#endif //BACKPROJECT_REMOVEIMAGE_H
