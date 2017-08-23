cmake_minimum_required(VERSION 3.2)
project(Backproject CXX)
project(csvparser CXX)

#Use C++ 11 features when compiling all code.
set(CMAKE_CXX_STANDARD 11)
#Give out as many warnings as possible, and when an error occurs, stop compilation; focusing on the first error is best.
set(CMAKE_CXX_FLAGS "-Wfatal-errors -Wall")

#create a library of the csv code.
add_library(csvparser thirdparty/fast-cpp-csv-parser/csv.h ${VerifyCXX})
set_target_properties(csvparser PROPERTIES LINKER_LANGUAGE CXX) #cmake cannot determine the language due to no .cpp files present.
#[[
Under linux, (not needed in windows) we need to link to the library that contains threading stuff
( threading is used by CSV library)
]]
if(UNIX)
    target_link_libraries(csvparser pthread)
endif(UNIX)



#add all source files (so that they're offered to the compiler and turned to o files)
set(SOURCE_FILES main.cpp Context/InteriorOrientation.cpp Context/InteriorOrientation.h Context/Image.cpp Context/Image.h Context/ExteriorOrientation.cpp Context/ExteriorOrientation.h util.h util.hpp util.cpp ReadCSV.cpp ReadCSV.h Context/Context.cpp Context/Context.h Context/Operations/ContextOperation.h Context/Operations/LoadImagesOperation.cpp Context/Operations/ContextOperation.cpp Context/Operations/LoadImagesOperation.cpp Context/Operations/LoadImagesOperation.h  Context/Operations/LoadHardCodedPointsOperation.cpp Context/Operations/LoadHardCodedPointsOperation.h Context/Operations/RemoveAllImagesOperation.cpp Context/Operations/RemoveAllImagesOperation.h Context/Operations/RemoveAllPointsOperation.cpp Context/Operations/RemoveAllPointsOperation.h Context/Operations/BackProjectAllPointsOperation.cpp Context/Operations/BackProjectAllPointsOperation.h Context/Operations/DisplayImageDetailsOperation.cpp Context/Operations/DisplayImageDetailsOperation.h Context/Operations/EnterPointsOperation.cpp Context/Operations/EnterPointsOperation.h matrix.cpp matrix.h Context/Operations/PurposelyBrokenOperation.cpp Context/Operations/PurposelyBrokenOperation.h)

#[[Note, to facilitate testing, we need to seperate the 'actual' code from the main function.
The code already supports this concept easily, so all that is required is making a seperate executable using main.cpp
and to link in the library created below.]]
add_library(BackprojectLibrary ${SOURCE_FILES})
target_link_libraries(BackprojectLibrary
        csvparser)


#create the main executable.
add_executable(Backproject main.cpp)
target_link_libraries(Backproject
        BackprojectLibrary
        csvparser)

#Copy our images.csv file.
configure_file(images.csv images.csv COPYONLY)
configure_file(invalid.csv invalid.csv COPYONLY)


#testing (this part is heavily inspired by and partially taken from: https://github.com/dmonopoly/gtest-cmake-example/blob/master/CMakeLists.txt)
add_subdirectory(thirdparty/googletest/googletest)
enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#create unittest executable and link in Backprojectlibrary as well as the gtest libraries
add_executable(runUnitTests UnitTests/RunTestCases.cpp UnitTests/RunTestCases.h)
target_link_libraries(runUnitTests gtest gtest_main BackprojectLibrary)