//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_CONTEXTOPERATION_H
#define BACKPROJECT_CONTEXTOPERATION_H

#include "ContextOperationBase.h"
#include "../Context.h"


//The code below adopts the pattern in the accepted answer of the following Stackoverflow:
//https://stackoverflow.com/questions/10332725/how-to-automatically-register-a-class-on-creation


class Context;

/**
 * Represents an operation that can be performed based on the 'Context'
 */
template<class T>  class ContextOperation : public ContextOperationBase {

protected:
    ContextOperation();
    static bool reg; //Registration object which places the object into the Context static list of properties.
    static bool init();

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
