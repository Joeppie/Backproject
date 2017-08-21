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

    /**
     * Registration of the stream operator as a friend
     * @param os  the stream instance to stream to
     * @param context the instance of the context being streamed
     * @return the stream, after it has been used to stream the context.
     */
    friend std::ostream &operator<<(std::ostream &os, const Context &context);

    /**
     * Adds operations to all contexts. Note; user must prevent adding operations twice.
     * @param operation operation to add.
     */
    static void registerOperation(std::shared_ptr<ContextOperation> operation);


    /**
     * Lists the operations in the context.
     * @return a list of the operations inside the context.
     */
    const std::vector<std::shared_ptr<ContextOperation>> &listOperations() const;

    /**
     * Returns the images that are in the context.
     * @return A vector containing shared pointers which keep references to the Images.
     */
    const std::vector<std::shared_ptr<Image>> listImages() const;

    /**
     * Returns the points in the context.
     * @return a vector containing all of the points (where a point is represented as a vector of doubles; x,y,z
     */
    const std::vector<std::vector<double>> listPoints() const;

    /**
     * Addsa  new image to the context
     * @param image the image to add
     */
    void addImage(const std::shared_ptr<Image> image);

    /**
     * Adds a new point to the context.
     * @param point the point to add.
     */
    void addPoint(const std::vector<double> point);

    /**
     * Removes all of the points in the context
     */
    void removeALlPoints();

    /**
     * 'Enter' the context and let the user interact with it
     * @param os Output stream to use
     * @param is Input stream to use
     */
    void Enter(std::ostream &os, std::istream &is);

};


#endif //BACKPROJECT_CONTEXT_H
