cmake_minimum_required(VERSION 3.8)
project(Backproject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -fpermissive")


set(SOURCE_FILES main.cpp thirdparty/csv.h Classes/InteriorOrientation.cpp Classes/InteriorOrientation.h Classes/Image.cpp Classes/Image.h Classes/ExteriorOrientation.cpp Classes/ExteriorOrientation.h util.h util.cpp ReadCSV.cpp ReadCSV.h Classes/Context/Context.cpp Classes/Context/Context.h Classes/Context/Operation/ContextOperation.h Classes/Context/Operation/LoadImagesFromCSV.cpp Classes/Context/Operation/ContextOperation.cpp)
add_executable(Backproject ${SOURCE_FILES})
configure_file(dummy.csv dummy.csv COPYONLY)


#[[
Under linux, (not needed in windows) we need to link to the library that contains threading stuff
( threading is used by CSV library)
]]
if(UNIX)
    target_link_libraries(Backproject pthread)
endif(UNIX)