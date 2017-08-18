//
// Created by LijnenJJ on 16-8-2017.
//

#ifndef BACKPROJECT_IMAGE_H
#define BACKPROJECT_IMAGE_H
#include <memory>

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
     *
     * @return the height of the image
     */
    int get_height() const;

    Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
          const std::shared_ptr<ExteriorOrientation> &_EO);


    bool backProject(vector worldCoordinate,Point2<double> &imageCoordinate);


    //Getters and setters
    /**
     *
     * @param _height sets the height of the image.
     **/
    void set_height(int _height);

    int get_width() const;

    void set_width(int _width);

    const std::string &get_fileName() const;

    void set_fileName(const std::string &_fileName);

    const std::shared_ptr<InteriorOrientation> &get_IO() const;

    void set_IO(const std::shared_ptr<InteriorOrientation> &_IO);

    const std::shared_ptr<ExteriorOrientation> &get_EO() const;

    void set_EO(const std::shared_ptr<ExteriorOrientation> &_EO);

private:
    std::shared_ptr<InteriorOrientation> _IO;
    std::shared_ptr<ExteriorOrientation> _EO;

};


#endif //BACKPROJECT_IMAGE_H
