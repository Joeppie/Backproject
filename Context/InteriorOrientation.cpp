
#include "InteriorOrientation.h"

double InteriorOrientation::get_focalLength() const
{
    return _focalLength;
}

void InteriorOrientation::set_focalLength(double focalLength)
{
    if (focalLength <= 0)
    {
        throw std::invalid_argument("IO focal length must be greater than zero");
    }
    InteriorOrientation::_focalLength = focalLength;
}

Point InteriorOrientation::get_principalPoint() const
{
    return _principalPoint;
}

void InteriorOrientation::set_principalPoint(Point principalPoint)
{
    if (principalPoint.x <= 0 || principalPoint.y <= 0)
    {
        throw std::invalid_argument("Principal point must not contain negative ordinates.");
    }
    InteriorOrientation::_principalPoint = principalPoint;
}
