#include "geometry/Cuboid.hpp"

Cuboid::Cuboid(const Transform3d pose, const double &widht, const double &length, const double &height)
    : Shape(pose), _width(widht), _length(length), _height(height)
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
            (std::string("Cuboid can only be indexed in the [0-7] range. Tried ") + std::to_string(i)));
    return _corners[i].getPosition();
}

Cuboid &Cuboid::operator=(const Cuboid &otherCuboid)
{
    _pose = otherCuboid._pose;
    _width = otherCuboid._width;
    _length = otherCuboid._length;
    _height = otherCuboid._height;
    updateCorners();
    return *this;
}

Cuboid Cuboid::operator*(const Transform3d &transform3d) const
{
    return Cuboid(Transform3d(_pose * transform3d), _width, _length, _height);
}

Cuboid &Cuboid::operator*=(const Transform3d &transform3d)
{
    *this = *this * transform3d;
    updateCorners();

    return *this;
}

void Cuboid::updateCorners()
{
    for (uint i = 0; i < 8; i++)
    {
        //[+ + +] [+ + -] [+ - +] [+ - -]  [- - +] [- - -] [- - +] [- + -] [- + +]
        Vector3d corner_displacement = Vector3d(_width * (i < 4 ? 0.5 : -0.5),
                                                _length * (i < 2 || i >= 6 ? 0.5 : -0.5),
                                                _height * (i % 2 == 0 ? 0.5 : -0.5)) *
                                       _pose.rotation();
        _corners[i] = _pose.translation() + corner_displacement;
    }
    return;
}