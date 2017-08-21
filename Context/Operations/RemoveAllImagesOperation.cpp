//
// Created by LijnenJJ on 21-8-2017.
//

#include "RemoveAllImagesOperation.h"


bool RemoveAllImagesOperation::IsPossible(const Context &context) const
{
    return context.listImages().size() > 0;
}

std::string RemoveAllImagesOperation::getDescription() const
{

    return "Remove all images from context.";
}

std::string RemoveAllImagesOperation::Perform(Context &context) const
{

    context.removeALlPoints();
    return "Removed all images from context.";
}
