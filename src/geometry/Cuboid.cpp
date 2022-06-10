#include "geometry/Cuboid.hpp"

Cuboid::Cuboid(const std::shared_ptr<Pose> pose, const double &widht, const double &length, const double &height)
: _centre(pose), _width(widht), _length(length), _height(height)
{
    updateCorners();
}

Cuboid::~Cuboid()
{
}

Vector3d Cuboid::operator[](const uint &i) const
{
    if (i < 0 || i > 7)
        throw std::runtime_error(
            (std::string("Cuboid can only be indexed in the [0-7] range. Tried ") 
            + std::to_string(i)));
    return _corners[i];
}

void Cuboid::updateCorners()
{
    for (uint i = 0; i < 8; i++)
    {
        //[+ + +] [+ + -] [+ - +] [+ - -]  [- - +] [- - -] [- - +] [- + -] [- + +] 
        Vector3d corner_displacement = Vector3d(_width * (i < 4 ? 0.5 : -0.5), 
                                        _length * (i < 2 || i >= 6 ? 0.5 : -0.5), 
                                        _height * (i % 2 == 0 ? 0.5 : -0.5)) 
                                        * _centre->rotation();
        _corners[i] = _centre->translation() + corner_displacement;
    }
    return;
}