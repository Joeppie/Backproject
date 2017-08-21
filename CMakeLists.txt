cmake_minimum_required(VERSION 3.8)
project(Backproject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -Wall")


set(SOURCE_FILES main.cpp thirdparty/csv.h Context/InteriorOrientation.cpp Context/InteriorOrientation.h Context/Image.cpp Context/Image.h Context/ExteriorOrientation.cpp Context/ExteriorOrientation.h util.h util.hpp util.cpp ReadCSV.cpp ReadCSV.h Context/Context.cpp Context/Context.h Context/Operations/ContextOperation.h Context/Operations/LoadImagesOperation.cpp Context/Operations/ContextOperation.cpp Context/Operations/LoadImagesOperation.cpp Context/Operations/LoadImagesOperation.h Context/Operations/RemoveImageOperation.cpp Context/Operations/RemoveImageOperation.h Context/Operations/LoadHardCodedPointsOperation.cpp Context/Operations/LoadHardCodedPointsOperation.h Context/Operations/RemoveAllImagesOperation.cpp Context/Operations/RemoveAllImagesOperation.h Context/Operations/RemoveAllPointsOperation.cpp Context/Operations/RemoveAllPointsOperation.h Context/Operations/BackProjectAllPointsOperation.cpp Context/Operations/BackProjectAllPointsOperation.h)
add_executable(Backproject ${SOURCE_FILES})
configure_file(dummy.csv dummy.csv COPYONLY)


#[[
Under linux, (not needed in windows) we need to link to the library that contains threading stuff
( threading is used by CSV library)
]]
if(UNIX)
    target_link_libraries(Backproject pthread)
endif(UNIX)