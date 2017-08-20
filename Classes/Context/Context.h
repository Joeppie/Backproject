//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_CONTEXT_H
#define BACKPROJECT_CONTEXT_H

#include <memory>
#include <vector>
#include <ostream>
#include "../Image.h"
#include "Operation/ContextOperation.h"


//Forward declaration: the two H files need eachother.
class ContextOperation;

/**
 * A context; keeps track  of overal program state in a way that is easily accessed by multiple functions.
 */
class Context {

public:
    std::vector<std::shared_ptr<Image>> Images;

    friend std::ostream &operator<<(std::ostream &os, const Context &context);

    Context();

    std::vector<std::vector<double>> Points;

    //TODO: fix it so that a list of the operations can be made and printed to cout.
    //the above shoudl lead to an extensible menu structure; of course, only print oeprations that report
    //ispossible == true
    static std::vector<std::shared_ptr<ContextOperation>> operations;
};






#endif //BACKPROJECT_CONTEXT_H
