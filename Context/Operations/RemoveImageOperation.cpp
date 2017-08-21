

#include "RemoveImageOperation.h"
#include "..\..\util.h"
#include <iomanip>

std::string RemoveImageOperation::Perform(Context &context) const
{
    return "Sorry, I was too lazy to implement yet another menu structure. \n Just clear all images instead - Regards Joep";
}

bool RemoveImageOperation::IsPossible(const Context &context) const
{
    return context.listImages().size() > 0;
}

std::string RemoveImageOperation::getDescription() const
{
    return "Removes a specific image from the context.";
}