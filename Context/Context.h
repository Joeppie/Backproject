//
// Created by root on 8/19/17.
//

#ifndef BACKPROJECT_CONTEXT_H
#define BACKPROJECT_CONTEXT_H

#include <memory>
#include <vector>
#include <ostream>
#include "Image.h"
#include "Operations/ContextOperation.h"


//Forward declaration: the two H files need eachother.
class ContextOperation;


/**
 * A context; keeps track  of overal program state in a way that is easily accessed by multiple functions.
 */
class Context
{

private:
    /**
     * operations are shared between all context objects.
     */
    static std::vector<std::shared_ptr<ContextOperation>> operations;

    std::vector<std::shared_ptr<Image>> Images;
    std::vector<std::vector<double>> Points;

public:


    friend std::ostream &operator<<(std::ostream &os, const Context &context);

    Context();

    /**
     * Adds operations to all contexts. Note; user must prevent adding operations twice.
     * @param operation operation to add.
     */
    static void registerOperation(std::shared_ptr<ContextOperation> operation);

    //TODO: fix it so that a list of the operations can be made and printed to cout.
    //the above shoudl lead to an extensible menu structure; of course, only print operations that report
    //ispossible == true
    const std::vector<std::shared_ptr<ContextOperation>> &listOperations() const;

    const std::vector<std::shared_ptr<Image>> listImages() const;

    const std::vector<std::vector<double>> listPoints() const;

    void addImage(const std::shared_ptr<Image> image);

    void addPoint(const std::vector<double> point);

    void removeALlPoints();

    void Enter(std::ostream &os, std::istream &is);

};


#endif //BACKPROJECT_CONTEXT_H
