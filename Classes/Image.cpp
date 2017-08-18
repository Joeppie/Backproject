//
// Created by LijnenJJ on 16-8-2017.
//

#include <math.h>
#include "Image.h"
#include "../util.h"

int Image::get_height() const
{
    return _height;
}

/*void Image::set_height(int _height)
{
    Image::_height = _height;
}*/

int Image::get_width() const
{
    return _width;
}

/*void Image::set_width(int _width)
{
    Image::_width = _width;
}*/

const std::string &Image::get_fileName() const
{
    return _fileName;
}

/*void Image::set_fileName(const std::string &_fileName)
{
    Image::_fileName = _fileName;
}*/

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

Image::Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
             const std::shared_ptr<ExteriorOrientation> &_EO) : _height(_height), _width(_width), _fileName(_fileName),
                                                                _IO(_IO), _EO(_EO)
{


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
                {0, 0, 0}};

    printMatrix(k);

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

    vector translation = this->_EO->get_translation();
    matrix columnVectorTranslation = {{translation[0]},
                                      {translation[1]},
                                      {translation[2]}};

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
#warning the calculation below will always fail; we're attempting to multiply a 3x3 mnatrix with a 3x4 one; this fails because the number of rows on the 2nd matrix must be equal to col on 1st
    matrix x = multiply(P, X); //P has 4 columns, but X is a column vector of length 3!

    printMatrix(x);

    imageCoordinate.x = x[0][0] / x[2][0];
    imageCoordinate.y = x[1][0] / x[2][0];

    //Return true when the image row-column coordinate calculated lies within the image.
    return
            imageCoordinate.x < this->_height && imageCoordinate.x > 0 &&
            imageCoordinate.y < this->_height && imageCoordinate.y > 0;
}

