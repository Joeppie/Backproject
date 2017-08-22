
#ifndef BACKPROJECT_INTERNALORIENTATION_H
#define BACKPROJECT_INTERNALORIENTATION_H

#include "../util.h"

/*!
 *
 */
class InteriorOrientation
{
public:
    /**
     * retrieves the focallength of the camera
     * @return the focal length of the camera in millimeters
     */
    double get_focalLength() const;

/**
 * sets the focal length of the camera
 * @param focalLength the focal length in millimeters.
 */
    void set_focalLength(double focalLength);

    /**
     * Retrieves the principal point of the image;
     * (wikipedia: The principal point is the point on the image plane onto which the perspective center is projected.
     * It is also the point from which the focal length of the lens is measured.)
     * @return the principal point expressed in pixels, x and y respectively.
     */
    Point get_principalPoint() const;

    /**
     * sets the principal point of the image
     * @param principalPoint
     */
    void set_principalPoint(Point principalPoint);

private:
    double _focalLength;
    Point _principalPoint;

};


#endif //BACKPROJECT_INTERNALORIENTATION_H
