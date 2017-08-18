//
// Created by LijnenJJ on 16-8-2017.
//

#include "InteriorOrientation.h"

Point2<double> InteriorOrientation::get_focalLength() const
{
    return _focalLength;
}

void InteriorOrientation::set_focalLength(Point2<double> _focalLength)
{
    InteriorOrientation::_focalLength = _focalLength;
}

Point2<double> InteriorOrientation::get_principalPoint() const
{
    return _principalPoint;
}

void InteriorOrientation::set_principalPoint(Point2<double> _principalPoint)
{
    InteriorOrientation::_principalPoint = _principalPoint;
}
