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
    std::vector<double> _rotation;
    std::vector<double> _translation;
public:
   const std::vector<double>  &get_rotation() const;

    void set_rotation(const std::vector<double> &_rotation);

    const std::vector<double> &get_translation() const;

    void set_translation(const std::vector<double> &_translation);

    /**
     *
     * @return A transformation matrix that contains the rotation and translation
     */
    matrix get_transformation();

};


#endif //BACKPROJECT_EXTERNALORIENTATION_H
