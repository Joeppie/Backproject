//
// Created by root on 8/19/17.
//

#include "Context.h"

Context::Context() {

}


//Required to be initialized here, so that linker can make sense of this, when referenced in the ContextOperations.
std::vector<std::shared_ptr<ContextOperationBase>> Context::operations;

std::ostream &operator<<(std::ostream &os, const Context &context) {
    //TODO: stream each operation as a a menu item,, setw(16) or so, prepend its index+1 in vector.
    //above will allow user to specify index+1 in input to indicate they want to run that operation.
    return os;
}

static void Context::registerOperation(ContextOperationBase& operation) {

}
