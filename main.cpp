#include <iostream>
#include <memory>
#include "util.h"

#include "Context/Context.h"
#include "Context/Operations/LoadImagesOperation.h"
#include "Context/Operations/LoadHardCodedPointsOperation.h"
#include "Context/Operations/RemoveImageOperation.h"
#include "Context/Operations/RemoveAllImagesOperation.h"
#include "Context/Operations/RemoveAllPointsOperation.h"
#include "Context/Operations/BackProjectAllPointsOperation.h"
#include "Context/Operations/DisplayImageDetailsOperation.h"

/**
 * Entry point of the program.
 * @return
 */
int main()
{
    std::cout << "Initializing Context object.." << std::endl;

    Context context;

    //Register operations, so that they can be chosen in the menu, shown when in Context::Enter.
    Context::registerOperation(std::shared_ptr<ContextOperation>(new LoadImagesOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new LoadHardCodedPointsOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new BackProjectAllPointsOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new DisplayImageDetailsOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveImageOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveAllImagesOperation));
    Context::registerOperation(std::shared_ptr<ContextOperation>(new RemoveAllPointsOperation));

    //Allow the user to interact with the context.
    context.Enter(std::cout, std::cin);

    return 0;
}