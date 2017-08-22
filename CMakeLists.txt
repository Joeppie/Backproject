cmake_minimum_required(VERSION 3.8)
project(Backproject)

#Use C++ 11 features when compiling all code.
set(CMAKE_CXX_STANDARD 11)
#Give out as many warnings as possible, and when an error occurs, stop compilation; focusing on the first error is best.
set(CMAKE_CXX_FLAGS "-Wfatal-errors -Wall")

#add all source files (so that they're offered to the compiler and turned to o files)
set(SOURCE_FILES main.cpp thirdparty/csv.h Context/InteriorOrientation.cpp Context/InteriorOrientation.h Context/Image.cpp Context/Image.h Context/ExteriorOrientation.cpp Context/ExteriorOrientation.h util.h util.hpp util.cpp ReadCSV.cpp ReadCSV.h Context/Context.cpp Context/Context.h Context/Operations/ContextOperation.h Context/Operations/LoadImagesOperation.cpp Context/Operations/ContextOperation.cpp Context/Operations/LoadImagesOperation.cpp Context/Operations/LoadImagesOperation.h  Context/Operations/LoadHardCodedPointsOperation.cpp Context/Operations/LoadHardCodedPointsOperation.h Context/Operations/RemoveAllImagesOperation.cpp Context/Operations/RemoveAllImagesOperation.h Context/Operations/RemoveAllPointsOperation.cpp Context/Operations/RemoveAllPointsOperation.h Context/Operations/BackProjectAllPointsOperation.cpp Context/Operations/BackProjectAllPointsOperation.h Context/Operations/DisplayImageDetailsOperation.cpp Context/Operations/DisplayImageDetailsOperation.h Context/Operations/EnterPointsOperation.cpp Context/Operations/EnterPointsOperation.h matrix.cpp matrix.h Context/Operations/PurposelyBrokenOperation.cpp Context/Operations/PurposelyBrokenOperation.h)

#Specifcy that an executable should be generated from the previous compilation units.
add_executable(Backproject ${SOURCE_FILES})

#Copy our images.csv file.
configure_file(images.csv images.csv COPYONLY)
configure_file(invalid.csv invalid.csv COPYONLY)

#[[
Under linux, (not needed in windows) we need to link to the library that contains threading stuff
( threading is used by CSV library)
]]
if(UNIX)
    target_link_libraries(Backproject pthread)
endif(UNIX)
