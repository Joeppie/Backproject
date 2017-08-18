//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_EXTERNALORIENTATION_H
#define BACKPROJECT_EXTERNALORIENTATION_H


#include "../util.h"


/**
 * Represents the External Orientation of an image.
 */
class ExteriorOrientation
{
private:
    vector _rotation;
    vector _translation;
public:
   const vector &get_rotation() const;

    /**
     * Sets rotation, in degrees as a vector with 3 elements; x y z
     * @param _rotation rotation vector, degrees
     */
    void set_rotation(const vector &_rotation);

    const vector &get_translation() const;

    void set_translation(const vector &_translation);

    /**
     *
     * @return A transformation matrix that contains the rotation and translation
     */
    matrix get_transformation();

};


#endif //BACKPROJECT_EXTERNALORIENTATION_H
