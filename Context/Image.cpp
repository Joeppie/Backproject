//
// Created by LijnenJJ on 16-8-2017.
//

#include <math.h>
#include "Image.h"
#include "../util.h"
#include <iomanip>

//constructors
Image::Image()
{}
Image::Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
             const std::shared_ptr<ExteriorOrientation> &_EO) : _height(_height), _width(_width), _fileName(_fileName),
                                                                _IO(_IO), _EO(_EO)
{}

//getters and setters.

int Image::get_height() const
{
    return _height;
}

void Image::set_height(int _height)
{
    Image::_height = _height;
}

int Image::get_width() const
{
    return _width;
}

void Image::set_width(int _width)
{
    Image::_width = _width;
}

const std::string &Image::get_fileName() const
{
    return _fileName;
}

void Image::set_fileName(const std::string &_fileName)
{
    Image::_fileName = _fileName;
}

const std::shared_ptr<InteriorOrientation> &Image::get_IO() const
{
    return _IO;
}

void Image::set_IO(const std::shared_ptr<InteriorOrientation> &_IO)
{
    Image::_IO = _IO;
}

const std::shared_ptr<ExteriorOrientation> &Image::get_EO() const
{
    return _EO;
}

void Image::set_EO(const std::shared_ptr<ExteriorOrientation> &_EO)
{
    Image::_EO = _EO;
}

bool Image::backProject(const vector& worldCoordinate, Point &imageCoordinate)
{

    //Create a column 'vector' (or really just a 3x1 matrix, so that we can multiply and happily use results.)
    matrix X = {{worldCoordinate[0]},
                {worldCoordinate[1]},
                {worldCoordinate[2]},
                {1}
    };

    printMatrix(X);

    //Backproject use the transpose of the rotation+translation matrix.
    //this->_eo->

    matrix transformation = this->_EO->get_transformation();
    //K=[F 0 cxp; 0 F cyp; 0 0 1]; %Camera matrix

    //Create camera matrix
    double f = this->get_IO()->get_focalLength();
    Point pp = this->get_IO()->get_principalPoint();

    //The camera matrix, it is populated with Interior Orientation information; focal length and principal point.
    matrix k = {{f, 0, pp.x},
                {0, f, pp.y},
                {0, 0, 1}};

    printMatrix(k);

    //Rotate camera properly into world frame

    const double deg_to_rad = M_PI/180.0;

    double pitch2 = 180*deg_to_rad;
    double yaw2 = 90*deg_to_rad;
    double roll2 = 0*deg_to_rad;

//Assemble outer rotation matrix

    const matrix rotationY2 = {{cos(pitch2)      ,0  ,sin(pitch2)},
                              {0           ,1  ,0},
                              {-sin(pitch2)     ,0  ,cos(pitch2)}};

    const matrix rotationX2 = {{1     ,0       ,0},
                              {0     ,cos(roll2)  ,-sin(roll2)},
                              {0     ,sin(roll2)  ,cos(roll2) }};

    const matrix rotationZ2 = {{cos(yaw2)      ,-sin(yaw2) ,0},
                              {sin(yaw2)      ,cos(yaw2)  ,0},
                              {0              ,0          ,1}};



    matrix RMtemp = multiply(multiply(rotationX2,rotationY2),rotationZ2);
    matrix RM = multiply(transformation, RMtemp);



    //Compute transpose - can be copied into util.cpp later

    matrix RMt (3,vector(3));

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
        {
            RMt[j][i]=RM[i][j];
        }



    //Relate translation component to world frame

    vector translation = this->_EO->get_translation();
    matrix columnVectorTranslation = {{translation[0]},
                                      {translation[1]},
                                      {translation[2]}};

    matrix RMtn = negate(RMt);
    matrix tR = multiply(RMtn,columnVectorTranslation);
    printMatrix(tR);

    //Concatenate rotation and translation elements

    matrix Rt = concatenate(RMt, tR);
    printMatrix(Rt);

    //Compute Projection matrix

    matrix P = multiply(k, Rt);

    printMatrix(P);


//Return image coordinates from object point

    matrix x = multiply(P, X);

    printMatrix(x);

    imageCoordinate.x = x[0][0] / x[2][0];
    imageCoordinate.y = x[1][0] / x[2][0];

    std::cout <<  imageCoordinate.x << std::endl;
    std::cout <<  imageCoordinate.y << std::endl;

    //Return true when the image row-column coordinate calculated lies within the image.
    return
            imageCoordinate.x < this->_height && imageCoordinate.x > 0 &&
            imageCoordinate.y < this->_height && imageCoordinate.y > 0;
}


std::_Setw indent(int level)
{
    const int indentSize = 8;
    return std::setw(level*indentSize);
}

/*template<class Tvalue>
std::ostream formatProperty(std::ostream &stream,const std::string& property,Tvalue value)
{
    stream << "filename" << indent(1) << value << "\n";
    return stream;
}*/

std::ostream& operator<<(std::ostream& stream, const Image& image) {
    stream << "Image" << "\n";
    stream << indent(1) <<  "filename" << indent(1) << image.get_fileName() << "\n";
    stream << indent(1) <<  "width" << indent(1) << image.get_width()<< "\n";
    stream << indent(1) <<  "height" << indent(1) << image.get_height() << "\n";


    stream << "\n";
    stream << indent(1) <<  "Interior Orientation" << "\n";
    stream << indent(2) <<  "focal length" << indent(1) << image.get_IO()->get_focalLength()   << "\n";
    stream << indent(2) <<  "Principal Point" << "\n";

    Point pp = image.get_IO()->get_principalPoint();
    stream << indent(3) <<  "x" << indent(1) << pp.x  << "\n";
    stream << indent(3) <<  "y" << indent(1) << pp.y << "\n";

    stream << "\n";
    stream << indent(1) <<  "Exterior Orientation" << "\n";
    vector rotation = image.get_EO()->get_rotation();
    stream << indent(2) <<  "rotation"   << "\n";
    stream << indent(3) <<  "x" << indent(1) << rotation[0]  << "\n";
    stream << indent(3) <<  "y" << indent(1) << rotation[1]  << "\n";
    stream << indent(3) <<  "z" << indent(1) << rotation[2]  << "\n";

    vector translation = image.get_EO()->get_translation();
    stream << indent(2) <<  "translation"   << "\n";
    stream << indent(3) <<  "x" << indent(1) << translation[0]  << "\n";
    stream << indent(3) <<  "y" << indent(1) << translation[1]  << "\n";
    stream << indent(3) <<  "z" << indent(1) << translation[2]  << "\n";

    return stream;
}

//Old code from getimagecoordinates.m
/*
    //This matrix is used to help create a transposed matrix.
    matrix rTranspose = {{1, 0,           0},
                         {0, cos(M_PI_2), -sin(M_PI_2)},
                         {0, sin(M_PI_2), cos(M_PI_2)}};

    printMatrix(rTranspose);

    //projection matrix is defined as P=K*[Rtranspose*RM -(Rtranspose*RM)*C];
    //The code below implements this.

    matrix rTranspose_X_Rm = multiply(rTranspose, transformation);

    printMatrix(rTranspose_X_Rm);

    //Create the negative version of the Rtranspose*RM matrix for second part of operation.
    matrix irTranspose = negate(rTranspose);

    printMatrix(irTranspose);

    //Todo: In matlab we would use world coordinates as a column vector, so that we can multiply it, in our C++ code, use a 1x3 matrix.



    matrix minus_RTranspose_x_RM_x_C = multiply(irTranspose, columnVectorTranslation);

    printMatrix(minus_RTranspose_x_RM_x_C);

    //Finally, we horizontally concatenate the two matrices: Rtranspose*RM and -(Rtranspose*RM)*C; that is to say; we add the fourth column to the first mentioned matrix.
    matrix K_x_Rtranspose_RM_concatenatedwith_iRtranspose_RM_x_C = concatenate(rTranspose_X_Rm,
                                                                               minus_RTranspose_x_RM_x_C);

    printMatrix(K_x_Rtranspose_RM_concatenatedwith_iRtranspose_RM_x_C);

    matrix P = multiply(k, K_x_Rtranspose_RM_concatenatedwith_iRtranspose_RM_x_C);
    /*
     * Matlab:
        x = P*X;
        xNorm(1,1)= x(1,1)/x(3,1);
        xNorm(2,1)= x(2,1)/x(3,1);
     */