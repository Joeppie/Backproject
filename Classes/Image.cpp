//
// Created by LijnenJJ on 16-8-2017.
//

#include "Image.h"
#include "../util.h"

int Image::get_height() const
{
    return _height;
}

/*void Image::set_height(int _height)
{
    Image::_height = _height;
}*/

int Image::get_width() const
{
    return _width;
}

/*void Image::set_width(int _width)
{
    Image::_width = _width;
}*/

const std::string &Image::get_fileName() const
{
    return _fileName;
}

/*void Image::set_fileName(const std::string &_fileName)
{
    Image::_fileName = _fileName;
}*/

const std::shared_ptr<InteriorOrientation> &Image::get_IO() const
{
    return _IO;
}

void Image::set_IO(const std::shared_ptr<InteriorOrientation> &_IO)
{
    Image::_IO = _IO;
}

const std::shared_ptr<ExteriorOrientation> &Image::get_EO() const
{
    return _EO;
}

void Image::set_EO(const std::shared_ptr<ExteriorOrientation> &_EO)
{
    Image::_EO = _EO;
}

Image::Image(int _height, int _width, const std::string &_fileName, const std::shared_ptr<InteriorOrientation> &_IO,
             const std::shared_ptr<ExteriorOrientation> &_EO) : _height(_height), _width(_width), _fileName(_fileName),
                                                                _IO(_IO), _EO(_EO)
{}

bool Image::backProject(vector worldCoordinate, Point2<double> &imageCoordinate)
{

    //Backproject use the transpose of the rotation+translation matrix.
    //this->_eo->


    matrix transformation = Image::_EO->get_transformation();



    return false;
}

