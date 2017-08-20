//
// Created by joep on 8/20/17.
//

#ifndef BACKPROJECT_CONTEXTOPERATIONBASE_H
#define BACKPROJECT_CONTEXTOPERATIONBASE_H


#include "../Context.h"


class Context;

/**
 * This class serves as a base for the template type ContextOperation.
 * Since a list is to be kept in the context, we need a type that can instantiated.
 * without this base class, it would not be possible.
 */
class ContextOperationBase {

public:
    /**
     * Returns whether the operation is possible given the current state of the context
     * @param context the context
     * @return true when the operation is possible.
     */
    virtual bool IsPossible(const Context &context) const =0;

    /**
     *
     * @return a short description of the operation.
     */
    virtual std::string getDescription() const =0;

    /**
     * Performs the operation on the context, thereby modifying it.
     * @param context
     * @return a string that reports the result of the operation; may be empty.
     */
    virtual std::string Perform(Context &context) const =0;

};


#endif //BACKPROJECT_CONTEXTOPERATIONBASE_H
