//
// Created by Joep on 21-8-2017.
//

#include "RemoveImageOperation.h"
#include "..\..\util.h"
#include <iomanip>

std::string RemoveImageOperation::Perform(Context &context) const {

/*


    int choice;


    auto getChoice = [&choice,&context]()
    {
        std::cout << "type the index of the image to remove;" << std::endl;
        int index = 1;
        std::cout << "[ 0 ] Abort/stop (does not remove anything)" << "\n";
        for(auto image : context.listImages())
        {
            std::cout << "[" << std::setw(3) << index++ << "]" <<  image->get_fileName() << "\n";
        }

        //Modify the value of the choice
       // choice = ReadAndValidate();
        choice = 0;
#warning fix the above statement please.

        //An interesting use for recursion; get a valid input.
        if(choice > index){
            std::cout << "That index does not exist, please enter a valid image index. " << "\n";
            getChoice();
        }
    };

    do
    {

    }
    while(choice != 0)
    {
        getChoice();
        if (choice != 0)
        {
            //Todo implement removal method for images.
            std::cout << "todo implement method that removes image from context, or make context friendly with every operation, or make public..." << std::endl;
        }
    }
*/


}

bool RemoveImageOperation::IsPossible(const Context &context) const {
    return context.listOperations().size() > 0;
}

std::string RemoveImageOperation::getDescription() const{
    return "Removes a specific image from the context.";
}