//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_CONTEXTOPERATION_H
#define BACKPROJECT_CONTEXTOPERATION_H


#include "../Context.h"


//forward declaration
class Context;

/**
 * Represents an operation that can be performed based on the 'Context'
 */
class ContextOperation {

protected:
    ContextOperation();

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
    virtual std::string Perform(Context &context) =0;

};


#endif //BACKPROJECT_CONTEXTOPERATION_H
