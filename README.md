# Backproject

This is a simple project which, using some [photogrammetry](https://en.wikipedia.org/wiki/Photogrammetry), implements the  back projection of world-space coordinates into the 2d pixel coordinates of an image.

The code is hosted also at https://github.com/Joeppie/Backproject

[![Documentation](https://codedocs.xyz/Joeppie/Backproject.svg)](https://codedocs.xyz/Joeppie/Backproject/files.html)
documented using codedocs.xyz

# Example usage/Demo

To get a feel of what the program can do, you can follow these steps:

- Run the program
- Type in 1 [enter] 
    - enter images.csv as filename [enter] 
- Type in 2 [enter]
- Type in 4 [enter]
    - [enter]  again

The above will; load in a csv with metadata for images, then load in a coordinate.
The backprojected coordinates wil then be shown.
    

# Building
You can use the git-clone command to check out the project to a local folder.

To build, run cmake on the source folder.

The code should compile on Linux, or minGW, it requires pthread and cmake.
 
#### Msys2/windows
Under windows, the code can be compiled under minGW, it has been tested using [msys2](http://www.msys2.org/).

The following packages are are required to be installed to build 64 bit:

    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-gcc-libs
    pacman -S mingw-w64-x86_64-gcc-libgfortran
    pacman -S mingw-w64-x86_64-gdb
    pacman -S mingw-w64-x86_64-make
    pacman -S mingw-w64-x86_64-libwinpthread-git
    pacman -S mingw-w64-x86_64-winpthreads-git
    pacman -S mingw-w64-x86_64-cmake
    pacman -S mingw64/mingw-w64-x86_64-gtest

Note: google test is also required; the package has been added.

### Linux
 git clone the repo, then use cmake to build the solution;
 
 The following steps have been tested under linux Mint terminal:
 
     git clone https://github.com/Joeppie/Backproject.git
     cd Backproject/
     cmake .
     make
 
 the executable will be Backproject and can be run using  ./Backproject
 
 You may first need to install and googletest pthread via the package manager of your distribution.
 
# code structure
 Class diagram still WIP:
![Class Diagram SVG](https://github.com/Joeppie/Backproject/blob/master/Class%20Diagram.png?raw=true)
(diagram created using draw.io)

# Third party-code / License

We use a CSV reading library written by Ben Strasser; https://github.com/ben-strasser/fast-cpp-csv-parser
This pertains to https://github.com/Joeppie/Backproject/blob/master/thirdparty/csv.h

Copyright: (2012-2015) Ben Strasser <code@ben-strasser.net>
License: BSD-3

# License

MIT License

Copyright (c) 2017 Joep Lijnen/ Phillipp Jende

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
