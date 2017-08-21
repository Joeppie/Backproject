//
// Created by root on 8/19/17.
//

#include "Context.h"
#include <iomanip>

Context::Context()
{

}


//Required to be initialized here, so that linker can make sense of this, when referenced in the ContextOperations.
std::vector<std::shared_ptr<ContextOperation>> Context::operations;

std::ostream &operator<<(std::ostream &os, const Context &context)
{
    //above will allow user to specify index+1 in input to indicate they want to run that operation.

    //Output a menu structure indicating the operations available.

    os << "BackProjection Context Object\n";

    os << context.listImages().size() << "images { ";
    for (auto image : context.listImages())
    {
        os << image->get_fileName() << " ";
    }
    os << "}\n";

    os << context.listImages().size() << "points { ";
    for (auto point : context.listPoints())
    {
        os << "{" << point[0] << "," << point[1] << "," << point[2] << "} ";
    }
    os << "}\n";

    os << context.listOperations().size() << " operations available.";

    return os;
}

void Context::registerOperation(std::shared_ptr<ContextOperation> operation)
{
    operations.push_back(operation);
}

const std::vector<std::shared_ptr<ContextOperation>> &Context::listOperations() const
{
    return Context::operations;
}

const std::vector<std::shared_ptr<Image>> Context::listImages() const
{
    return this->Images;
}

const std::vector<std::vector<double>> Context::listPoints() const
{
    return this->Points;
}

void Context::addImage(const std::shared_ptr<Image> image)
{

    std::cout << *image << std::endl;
    this->Images.push_back(image);
}

void Context::addPoint(const std::vector<double> point)
{
    this->Points.push_back(point);
}

void Context::Enter(std::ostream &os, std::istream &is)
{
    for (;;)
    {
        os << *this << "\n";
        int index = 1;
        for (std::shared_ptr<ContextOperation> operation : this->listOperations())
        {
            if (operation->IsPossible(*this))
            {
                os << "[" << std::setw(3) << index << "]";
            }
            else
            {
                os << "*N/A*";
            }

            os << "   " << operation->getDescription() << "\n";
            index++;
        }

        os << "[" << std::setw(3) << index << "]   Exit\n\n";


        unsigned int choice = ReadAndValidate<unsigned int>();


        //invalid choice, try again.
        if (choice == 0 || choice > Context::operations.size() + 1)
        {
            continue;
        }
            //user
        else if (choice == Context::operations.size() + 1)
        {
            return; //exits.
        }
        else //Input is valid index+1 of the extant operations
        {
            std::shared_ptr<ContextOperation> operation = Context::operations[choice - 1];
            if (operation->IsPossible(*this))
            {
                os << operation->Perform(*this) << std::endl;
            }
            else
            {
                os << "Sorry, is currently not possible to " << operation->getDescription() << "." << std::endl;
            }
        }

    }


}

void Context::removeALlPoints()
{
    this->Points.clear();
}

