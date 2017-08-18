cmake_minimum_required(VERSION 3.8)
project(Backproject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -fpermissive")


set(SOURCE_FILES main.cpp thirdparty/csv.h Classes/InteriorOrientation.cpp Classes/InteriorOrientation.h Classes/Image.cpp Classes/Image.h Classes/ExteriorOrientation.cpp Classes/ExteriorOrientation.h util.h util.cpp ReadCSV.cpp ReadCSV.h)
add_executable(Backproject ${SOURCE_FILES})
configure_file(dummy.csv dummy.csv COPYONLY)