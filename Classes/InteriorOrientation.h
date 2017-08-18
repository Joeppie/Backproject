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
    Point2<double> get_focalLength() const;

    void set_focalLength(Point2<double> _focalLength);

    Point2<double> get_principalPoint() const;

    void set_principalPoint(Point2<double> _principalPoint);

private:
    Point2<double> _focalLength;
    Point2<double> _principalPoint;

public:
/*    const double getFocalLength();
    const double getPrincipalPoint();

    void setFocalLength(const double &value);
    void setPrincipalPoint(const double &value);*/
};


#endif //BACKPROJECT_INTERNALORIENTATION_H
