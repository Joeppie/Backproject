//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_CONTEXTOPERATION_H
#define BACKPROJECT_CONTEXTOPERATION_H

#include "ContextOperation.h"
#include "../Context.h"


//The code below adopts the pattern in the accepted answer of the following Stackoverflow:
//https://stackoverflow.com/questions/10332725/how-to-automatically-register-a-class-on-creation


class Context;

/**
 * Represents an operation that can be performed based on the 'Context'
 */
class ContextOperation
{

public:
    /**
     * Indicates whether the operation can be performed given the current state of affairs.
     * @param context the context for which the operation may be runnable
     * @return true when the operation may be performed
     */
    virtual bool IsPossible(const Context &context) const =0;

    /**
     * Gives a short (infinitive verb) indication of what the operation does
     * @return e.g. "use the context to do something"
     */
    virtual std::string getDescription() const =0;

    /**
     * Performs the operation on the context
     * @param context the context onto which to perform the operatoin
     * @return a string detailing the results of the operation
     */
    virtual std::string Perform(Context &context) const =0;

};


#endif //BACKPROJECT_CONTEXTOPERATION_H
