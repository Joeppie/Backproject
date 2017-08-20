//
// Created by LijnenJJ on 16-8-2017.
//

#include <math.h>
#include "ExteriorOrientation.h"

const std::vector<double>& ExteriorOrientation::get_rotation() const
{
    return _rotation;
}

void ExteriorOrientation::set_rotation(const std::vector<double> &_rotation)
{
    ExteriorOrientation::_rotation = _rotation;
}

const std::vector<double> &ExteriorOrientation::get_translation() const
{
    return _translation;
}

void ExteriorOrientation::set_translation(const std::vector<double> &_translation)
{
    ExteriorOrientation::_translation = _translation;
}

matrix ExteriorOrientation::get_transformation()
{
    const double deg_to_rad = M_PI/180.0;
    //Matrices for rotations around various axes
    const double y = ExteriorOrientation::_rotation[1]*deg_to_rad;
    const double x = ExteriorOrientation::_rotation[0]*deg_to_rad;
    const double z = ExteriorOrientation::_rotation[2]*deg_to_rad;

    /*rty=[cos(pitch*degtorad_i),0, sin(pitch*degtorad_i);
            0 , 1, 0;
            -sin(pitch*degtorad_i),0,cos(pitch*degtorad_i)];*/

    const matrix rotationY = {{cos(y)      ,0  ,sin(y)},
                        {0           ,1  ,0},
                        {-sin(y)     ,0  ,cos(y)}};


    /*
    %Rotation x
    rtx=[1,0,0;
    0, cos(roll*degtorad_i),-sin(roll*degtorad_i);
    0, sin(roll*degtorad_i),cos(roll*degtorad_i)];
    %Rotation z
    */

    const matrix rotationX = {{1     ,0       ,0},
                        {0     ,cos(x)  ,-sin(x)},
                        {0     ,sin(x)  ,cos(x) }};

/*

    rtz=[cos(yaw*degtorad_i),-sin(yaw*degtorad_i),0;
            sin(yaw*degtorad_i),cos(yaw*degtorad_i),0;
            0,0,1];

*/
   const matrix rotationZ = {{cos(z)      ,-sin(z) ,0},
                        {sin(z)      ,cos(z)  ,0},
                        {0              ,0          ,1}};


    //Finally:  RM=rty*rtx*rtz;
    //Implement the above as (y*x)*z, by using the matrix multiplication method... we should consider using a class with the * operator, for convenience
    matrix RM = multiply(multiply(rotationY,rotationX),rotationZ);


    return RM; //Rotation matrix.
}

ExteriorOrientation::ExteriorOrientation()
{}
