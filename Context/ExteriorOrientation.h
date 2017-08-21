
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
    /**
 *  Returns the rotation
 * @return rotation as a vector of doubles, containing rotations for respectively x,y,z
 */
    const vector &get_rotation() const;

/**
 * sets the rotation
 * @param rotation rotation as a vector of doubles, containing rotation for respectively x,y,z
 */
    void set_rotation(const vector &rotation);

/**
 * returns the translation
 * @return  translation as a vector of doubles, containing translation for respectively x,y,z
 */
    const vector &get_translation() const;

/**
 * sets the translation
 * @param _translation translation as a vector of doubles, containing translation for respectively x,y,z
 */
    void set_translation(const vector &_translation);


/**
 * Returns the rotation-matrix that is constructed by processing the rotation all three axes.
 * @return a matrix (std::vector<std::vector<double>>) that can be used in matrix-multiplication or vector-matrix multiplication
 */
    matrix get_transformation();

};


#endif //BACKPROJECT_EXTERNALORIENTATION_H
