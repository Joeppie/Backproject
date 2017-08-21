# Backproject

This is a simple project which implements a backprojection of world-space coordinates into the 2d pixel coordinates of an image.

# Building
To build, run cmake on the root folder.

The code should compile on Linux and Windows (using minGW on windows; msys2 is a good option)

You can use the git-clone command to check out the project to a local folder.
Afterward, run cmake and then make.

Users of the clion IDE can also import the code from the folder to whence Backproject was cloned.

# Third party-code

We use a CSV reading library written by Ben Strasser; https://github.com/ben-strasser/fast-cpp-csv-parser
This pertains to https://github.com/Joeppie/Backproject/blob/master/thirdparty/csv.h

Copyright: (2012-2015) Ben Strasser <code@ben-strasser.net>
License: BSD-3
