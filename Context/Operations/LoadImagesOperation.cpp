
#include <sstream>

#include "LoadImagesOperation.h"
#include "../Context.h"
#include "../../ReadCSV.h"


std::string LoadImagesOperation::Perform(Context &context) const
{
    try {
        std::string fileName;

        std::cout
                << "please enter the full filename of the csv containing the complete image metadata (hint: images.csv is an existing file)\n>";
        std::cout.flush();
        std::cin >> fileName;
        std::cin.ignore(1, '\n');
        auto images = ReadImageCsv(fileName);

        //Add each of the images (std::shared_ptr<Image> to the images known in the Context.)
        for (auto image :  images) {
            context.addImage(image);
        }
        std::stringstream fmt;
        fmt << "Succesfully loaded " << images.size() << " from " << fileName << ".\n";
        return fmt.str();
    }

    catch( const std::invalid_argument& e ) {
        std::stringstream fmt;
        fmt << "The following input error was found loading the file: "  << e.what() << "\n";
        return fmt.str();
    }
    catch (const std::exception &e)
    {
        std::stringstream fmt;
        fmt << "An unknown error occured loading the file: "  << e.what() << "\n";
        return fmt.str();
    }
}

bool LoadImagesOperation::IsPossible(const Context &context) const
{

    return true;
}

std::string LoadImagesOperation::getDescription() const
{
    return "load images from specific CSV file";
}
