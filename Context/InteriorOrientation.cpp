
#include "InteriorOrientation.h"

double InteriorOrientation::get_focalLength() const
{
    return _focalLength;
}

void InteriorOrientation::set_focalLength(double _focalLength)
{
    InteriorOrientation::_focalLength = _focalLength;
}

Point InteriorOrientation::get_principalPoint() const
{
    return _principalPoint;
}

void InteriorOrientation::set_principalPoint(Point _principalPoint)
{
    InteriorOrientation::_principalPoint = _principalPoint;
}
