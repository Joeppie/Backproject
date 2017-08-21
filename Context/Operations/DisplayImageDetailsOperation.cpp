//
// Created by LijnenJJ on 21-8-2017.
//

#include "DisplayImageDetailsOperation.h"

 bool DisplayImageDetailsOperation::IsPossible(const Context &context) const
 {
    return context.listImages().size() > 0;
 }
 std::string DisplayImageDetailsOperation::getDescription() const
 {
     return "display loaded image metadata";
 }
 std::string DisplayImageDetailsOperation::Perform(Context &context) const
 {
     //print every message to cout using the implemented << operator.
     for(auto image : context.listImages())
     {
         std::cout << *image << std::endl;
         PressEnterToContinue();
     }

     return "";
 }
