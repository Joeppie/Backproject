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
    virtual bool IsPossible(const Context &context) const =0;

    virtual std::string getDescription() const =0;

    virtual std::string Perform(Context &context) const =0;

};


#endif //BACKPROJECT_CONTEXTOPERATION_H
