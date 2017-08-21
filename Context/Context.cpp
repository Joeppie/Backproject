//
// Created by root on 8/19/17.
//

#include "Context.h"
#include <iomanip>

Context::Context() {

}


//Required to be initialized here, so that linker can make sense of this, when referenced in the ContextOperations.
std::vector<std::shared_ptr<ContextOperation>> Context::operations;

std::ostream &operator<<(std::ostream &os, const Context &context) {
    //above will allow user to specify index+1 in input to indicate they want to run that operation.



    //Output a menu structure indicating the operations available.
    int index =0;
    for(std::shared_ptr<ContextOperation> operation : context.listOperations())
    {
        if(operation->IsPossible(context))
        {
            os << "[" << std::setw(3) <<  index << "]";
        }
        else
        {
            os << "*N/A*";
        }

        os << "   "<< operation->getDescription() << "\n";
        index++;
    }


    return os;
}

void Context::registerOperation(std::shared_ptr<ContextOperation> operation) {
    operations.push_back(operation);
}

std::vector<std::shared_ptr<ContextOperation>>& Context::listOperations() const{
    return Context::operations;
}

//TODO: something weird is going on; compile error occurs when trying to use const here, due to discarding of qualifier?
std::vector<std::shared_ptr<Image>> Context::listImages() {
    return this->Images;
}

