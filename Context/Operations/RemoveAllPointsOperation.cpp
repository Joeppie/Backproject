
#include "RemoveAllPointsOperation.h"

bool RemoveAllPointsOperation::IsPossible(const Context &context) const
{
    return context.listPoints().size() > 0;
}

std::string RemoveAllPointsOperation::getDescription() const
{
    return "remove all points";
}

std::string RemoveAllPointsOperation::Perform(Context &context) const
{
    context.removeAllPoints();
    return "removed all points from context.";
}