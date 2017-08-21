

#ifndef BACKPROJECT_ENTERPOINTSOPERATION_H
#define BACKPROJECT_ENTERPOINTSOPERATION_H


#include "ContextOperation.h"

class EnterPointsOperation : public ContextOperation {
public:
    virtual bool IsPossible(const Context &context) const;
    virtual std::string getDescription() const;
    virtual std::string Perform(Context &context) const;
};


#endif //BACKPROJECT_ENTERPOINTSOPERATION_H
