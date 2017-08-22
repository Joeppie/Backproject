#include <math.h>
#include "Image.h"
#include "../util.h"
#include <iomanip>
#include <stdexcept>
#include <sstream>

//constructors
Image::Image() {}

Image::Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
             const std::shared_ptr<ExteriorOrientation> &_EO) : _height(_height), _width(_width), _fileName(_fileName),
                                                                _IO(_IO), _EO(_EO) {}

//getters and setters.

int Image::get_height() const {
    return _height;
}

void Image::set_height(int height) {
    if (height <= 0) {
        throw std::invalid_argument("Image height must be greater than zero.");
    }
    Image::_height = height;
}

int Image::get_width() const {
    return _width;
}

void Image::set_width(int width) {
    if (width <= 0) {
        throw std::invalid_argument("Image width must be greater than zero.");
    }
    Image::_width = width;
}

const std::string &Image::get_fileName() const {
    return _fileName;
}

void Image::set_fileName(const std::string &fileName) {
    Image::_fileName = fileName;
}

const std::shared_ptr<InteriorOrientation> &Image::get_IO() const {
    return _IO;
}

void Image::set_IO(const std::shared_ptr<InteriorOrientation> &IO) {
    if (IO.get() == nullptr) {
        throw std::invalid_argument("Image IO must not contain nullptr.");
    }
    auto pp = IO->get_principalPoint();
    if (pp.x <= 0 || pp.y <= 0 || pp.x > this->_width || pp.y > this->_height) {
        throw std::invalid_argument("Error: IO specifies that principal point lies outside of image.");
    }
    Image::_IO = IO;
}

const std::shared_ptr<ExteriorOrientation> &Image::get_EO() const {
    return _EO;
}

void Image::set_EO(const std::shared_ptr<ExteriorOrientation> &EO) {
    if (EO.get() == nullptr) {
        throw std::invalid_argument("Image EO must not contain nullptr.");
    }
    Image::_EO = EO;
}

bool Image::backProject(const vector &worldCoordinate, Point &imageCoordinate) {

//Avoid spamming when normally executing program (due to printmatrix statements that help debug)


    //Create a column 'vector' (or really just a 3x1 matrix, so that we can multiply and happily use results.)
    matrix X = {{worldCoordinate[0]},
                {worldCoordinate[1]},
                {worldCoordinate[2]},
                {1}
    };


    /*printMatrix(X);*/

    //Backproject use the transpose of the rotation+translation matrix.

    matrix transformation = this->_EO->get_transformation();
    //K=[F 0 cxp; 0 F cyp; 0 0 1]; %Camera matrix

    //Create camera matrix
    double f = this->get_IO()->get_focalLength();
    Point pp = this->get_IO()->get_principalPoint();

    //The camera matrix, it is populated with Interior Orientation information; focal length and principal point.
    matrix k = {{f, 0, pp.x},
                {0, f, pp.y},
                {0, 0, 1}};

    std::stringstream fmt;
    fmt << this->_fileName << " Camera matrix";
    printMatrix(k, fmt.str());

    //Rotate camera properly into world frame
    const double deg_to_rad = M_PI / 180.0;

    double pitch2 = 180 * deg_to_rad;
    double yaw2 = 90 * deg_to_rad;
    double roll2 = 0 * deg_to_rad;

    //Assemble outer rotation matrix

    const matrix rotationY2 = {{cos(pitch2),  0, sin(pitch2)},
                               {0,            1, 0},
                               {-sin(pitch2), 0, cos(pitch2)}};

    const matrix rotationX2 = {{1, 0,          0},
                               {0, cos(roll2), -sin(roll2)},
                               {0, sin(roll2), cos(roll2)}};

    const matrix rotationZ2 = {{cos(yaw2), -sin(yaw2), 0},
                               {sin(yaw2), cos(yaw2),  0},
                               {0,         0,          1}};

    matrix RMtemp = multiply(multiply(rotationX2, rotationY2), rotationZ2);
    matrix RM = multiply(transformation, RMtemp);

    //Compute transpose
    matrix RMt = transpose(RM);


    //Relate translation component to world frame
    vector translation = this->_EO->get_translation();
    matrix columnVectorTranslation = {{translation[0]},
                                      {translation[1]},
                                      {translation[2]}};

    matrix RMtn = negate(RMt);
    matrix tR = multiply(RMtn, columnVectorTranslation);
    /*printMatrix(tR);*/

    //Concatenate rotation and translation elements
    matrix Rt = concatenate(RMt, tR);
    /*printMatrix(Rt);*/

    //Compute Projection matrix
    matrix P = multiply(k, Rt);

    std::stringstream fmt2;
    fmt2 << this->_fileName << " Projection Matrix";
    printMatrix(P, fmt2.str());


    //Return image coordinates from object point
    matrix x = multiply(P, X);
    /*printMatrix(x);*/

    imageCoordinate.x = x[0][0] / x[2][0];
    imageCoordinate.y = x[1][0] / x[2][0];



    //Return true when the image row-column coordinate calculated lies within the image.
    return
            imageCoordinate.x < this->_height && imageCoordinate.x > 0 &&
            imageCoordinate.y < this->_height && imageCoordinate.y > 0;
}

std::_Setw indent(int level) {
    const int indentSize = 12;
    return std::setw(level * indentSize);
}

std::ostream &operator<<(std::ostream &stream, const Image &image) {
    stream << indent(1) << std::left << "filename: " << indent(1) << image.get_fileName() << "\n";
    stream << indent(1) << std::left << "width: " << indent(1) << image.get_width() << "\n";
    stream << indent(1) << std::left << "height: " << indent(1) << image.get_height() << "\n";

    stream << "\n";
    stream << indent(1) << std::left << "\nInterior Orientation:" << "\n";
    stream << indent(2) << std::left << "  focal length: " << indent(1) << image.get_IO()->get_focalLength() << "\n";

    stream << indent(2) << std::left << "\n  Principal Point: " << "\n";
    Point pp = image.get_IO()->get_principalPoint();
    stream << indent(3) << std::left << "    x: " << indent(1) << pp.x << "\n";
    stream << indent(3) << std::left << "    y: " << indent(1) << pp.y << "\n";

    stream << "\n";
    stream << indent(1) << std::left << "\nExterior Orientation:" << "\n";
    vector rotation = image.get_EO()->get_rotation();
    stream << indent(1) << std::left << "\n  rotation:" << "\n";
    stream << indent(1) << std::left << "    roll: " << indent(1) << rotation[0] << "\n";
    stream << indent(1) << std::left << "    pitch: " << indent(1) << rotation[1] << "\n";
    stream << indent(1) << std::left << "    yaw: " << indent(1) << rotation[2] << "\n";

    vector translation = image.get_EO()->get_translation();
    stream << indent(1) << std::left << "\n  translation:" << "\n";
    stream << indent(1) << std::left << "    x: " << indent(1) << translation[0] << "\n";
    stream << indent(1) << std::left << "    y: " << indent(1) << translation[1] << "\n";
    stream << indent(1) << std::left << "    z: " << indent(1) << translation[2] << "\n";

    return stream;
}