//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_IMAGE_H
#define BACKPROJECT_IMAGE_H

#include <memory>
#include <iostream>

#include "../util.h"
#include "InteriorOrientation.h"
#include "ExteriorOrientation.h"


class Image
{
private:
    int _height;
    int _width;
    std::string _fileName;

private:

public:

    /**
     * Constructs an image object with the given properties
     * @param _height  the height of the image in pixels
     * @param _width  the width of the image in pixels
     * @param _fileName  the filename of the image
     * @param _IO  the interior orientation of the image
     * @param _EO the exterior orientation of the image
     */
    Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
          const std::shared_ptr<ExteriorOrientation> &_EO);

    Image();

/**
 * Back-projects a 3d world coordinate into the image
 * @param worldCoordinate the vector containing the x,y and z ordinates.
 * @param imageCoordinate the point object that will contain the projected pixel coordinates of the object.
 * @return
 */
    bool backProject(const vector &worldCoordinate, Point &imageCoordinate);


    //Getters and setters

    /**
     *
     * @param _height sets the height of the image.
     **/
    void set_height(int _height);

    /**
     *
     * @return the height of the image
     */
    int get_height() const;

    /**
     *
     * @return the width of the image in pixels
     */
    int get_width() const;

    /**
     *
     * @param _width the width of the image in pixels
     */
    void set_width(int _width);

    /**
     * gets the filename of the image
     * @return the filename and path relative to the working directory of the executable.
     */
    const std::string &get_fileName() const;

    /**
     * sets the filename of the image
     * @param _fileName  the filename and path, relative to the working directory of the executable.
     */
    void set_fileName(const std::string &_fileName);

    /**
     * retrieves the Interior Orientation of the image
     * @return the InteriorOrientation
     */
    const std::shared_ptr<InteriorOrientation> &get_IO() const;

    /**
     * sets the Interior Orientation of the image
     * @param _IO the InteriorOrientation
     */
    void set_IO(const std::shared_ptr<InteriorOrientation> &_IO);

    /**
     * retrieves the Exterior Orientation of the image
     * @return the ExteriorOrientation
     */
    const std::shared_ptr<ExteriorOrientation> &get_EO() const;

    /**
     * sets the Exterior Orientation of the image
     * @param _IO the ExteriorOrientation
     */
    void set_EO(const std::shared_ptr<ExteriorOrientation> &_EO);

private:
    std::shared_ptr<InteriorOrientation> _IO;
    std::shared_ptr<ExteriorOrientation> _EO;

};

/**
 * stream operator declaration for Image
 * @param stream the stream to stream the information of the image to
 * @param image the image of which to stream implementation
 * @return the stream after the image information has been streamed to it.
 */
std::ostream &operator<<(std::ostream &stream, const Image &image);


#endif //BACKPROJECT_IMAGE_H
