//
// Created by Joep on 22-8-2017.
//

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdexcept>
#include "PurposelyBrokenOperation.h"

bool PurposelyBrokenOperation::IsPossible(const Context &context) const
{
    return true;
}
std::string PurposelyBrokenOperation::getDescription() const
{
  return "throw an exception";
}
std::string PurposelyBrokenOperation::Perform(Context &context) const
{
    /* initialize random seed: */
    srand (time(NULL));
    int i= rand() % 3;

    switch(i)
    {
        case 0: throw  std::invalid_argument("Image IO must not contain nullptr.");
        case 1:  throw std::exception();
        default: return "the operation has unexpectedly succeeded.";
    }

    throw std::invalid_argument("This point is never reached.");
}