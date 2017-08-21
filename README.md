# Backproject

This is a simple project which, using some [photogammetry](https://en.wikipedia.org/wiki/Photogrammetry), implements a backprojection of world-space coordinates into the 2d pixel coordinates of an image.



# Building
You can use the git-clone command to check out the project to a local folder.

To build, run cmake on the source folder.

The code should compile on Linux, or minGW, it requires pthread and cmake.
 
#### Msys2/windows
Under windows, the code can be compiled under minGW, it has been tested using [msys2](http://www.msys2.org/).


The following packages are are required to be installed to build 64 bit:

    pacman -Ss mingw-w64-x86_64-gcc
    pacman -Ss mingw-w64-x86_64-gcc-libs
    pacman -Ss mingw-w64-x86_64-gcc-libgfortran
    pacman -Ss mingw-w64-x86_64-gdb
    pacman -Ss mingw-w64-x86_64-make
    pacman -Ss mingw-w64-x86_64-libwinpthread-git
    pacman -Ss mingw-w64-x86_64-winpthreads-git
    pacman -Ss mingw-w64-x86_64-cmake


### Linux
 git clone the repo, then use cmake to build the solution. 
 
 You may first need to install pthread via the package manager of your distribution.
 
#code structure

![Alt text](/Class%20Diagram.svg?raw=true "Optional Title")

# Third party-code

We use a CSV reading library written by Ben Strasser; https://github.com/ben-strasser/fast-cpp-csv-parser
This pertains to https://github.com/Joeppie/Backproject/blob/master/thirdparty/csv.h

Copyright: (2012-2015) Ben Strasser <code@ben-strasser.net>
License: BSD-3
