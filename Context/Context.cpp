
#include <limits>
#include "Context.h"
#include <iomanip>

//Required to be initialized here, so that linker can make sense of this, when referenced in the ContextOperations.
std::vector<std::shared_ptr<ContextOperation>> Context::operations;

std::ostream &operator<<(std::ostream &os, const Context &context)
{
    //Output the pertinent information of the context to the stream.
    os << "Back projection Context Object\n";

    os << std::setw(4) << context.listImages().size() << "    images { ";
    for (auto image : context.listImages())
    {
        os << image->get_fileName() << " ";
    }
    os << "}\n";

    os << std::setw(4) << context.listPoints().size() << "    points { ";
    for (auto point : context.listPoints())
    {
        os << "{" << point[0] << "," << point[1] << "," << point[2] << "} ";
    }
    os << "}\n";

    os<< std::setw(4)  << context.listOperations().size() << "    operations available.";

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
        clearScreen();
        os << *this << "\n\n";
        int index = 1;
        for (std::shared_ptr<ContextOperation> operation : this->listOperations())
        {
            if (operation->IsPossible(*this))
            {
                os  << "    [ " << std::setw(1) << index << " ]";
            }
            else
            {
                os << "    [N/A]";
            }

            os << "       " << operation->getDescription() << "\n";
            index++;
        }

        os << "    [ " << std::setw(1) << index << " ]       Exit\n" << std::endl;

        unsigned int choice = ReadAndValidate<unsigned int>();

        //invalid choice, try again.
        if (choice == 0 || choice > Context::operations.size() + 1)
        {
            os << "That is not an option." << std::endl;
            PressEnterToContinue(os,is);
            continue;
        }

        //Process valid input; either an operation, or exiting.
        if (choice == Context::operations.size() + 1)
        {
            os << "Exiting";
            os.flush();
            for (int i = 0; i < 4; ++i)
            {
                sleep(.5);
                os << ".";
                os.flush();
            }

            return; //exits.
        }
        else //Input is valid index+1 of the extant operations
        {
            std::shared_ptr<ContextOperation> operation = Context::operations[choice - 1];
            if (operation->IsPossible(*this))
            {
                clearScreen();
                try {
                os << operation->Perform(*this) << std::endl;
                }
                catch(...)
                {
                    os << "An unexpected error occured trying to perform the operation." << std::endl;
                }
                PressEnterToContinue(os,is);
            }
            else
            {
                os << "Sorry, is currently not possible to " << operation->getDescription() << "." << std::endl;
                PressEnterToContinue(os,is);
            }
        }

    }
}

void Context::removeALlPoints()
{
    this->Images.clear();
}

