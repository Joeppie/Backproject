//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_INTERNALORIENTATION_H
#define BACKPROJECT_INTERNALORIENTATION_H

#include "../util.h"

/*!
 *
 */
class InteriorOrientation
{
public:
    double get_focalLength() const;

    void set_focalLength(double _focalLength);

    Point get_principalPoint() const;

    void set_principalPoint(Point _principalPoint);

private:
    double _focalLength;
    Point _principalPoint;

public:
/*    const double getFocalLength();
    const double getPrincipalPoint();

    void setFocalLength(const double &value);
    void setPrincipalPoint(const double &value);*/
};


#endif //BACKPROJECT_INTERNALORIENTATION_H
