cmake_minimum_required(VERSION 3.8)
project(Backproject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -fpermissive")


set(SOURCE_FILES main.cpp thirdparty/csv.h Context/InteriorOrientation.cpp Context/InteriorOrientation.h Context/Image.cpp Context/Image.h Context/ExteriorOrientation.cpp Context/ExteriorOrientation.h util.h util.cpp ReadCSV.cpp ReadCSV.h Context/Context.cpp Context/Context.h Context/Operations/ContextOperation.h Context/Operations/LoadImagesFromCSV.cpp Context/Operations/ContextOperation.cpp Context/Operations/ContextOperationBase.cpp Context/Operations/ContextOperationBase.h)
add_executable(Backproject ${SOURCE_FILES})
configure_file(dummy.csv dummy.csv COPYONLY)


#[[
Under linux, (not needed in windows) we need to link to the library that contains threading stuff
( threading is used by CSV library)
]]
if(UNIX)
    target_link_libraries(Backproject pthread)
endif(UNIX)