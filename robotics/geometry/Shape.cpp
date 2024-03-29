#include "geometry/Shape.hpp"

using namespace geometry;
using namespace math;

Shape::Shape(const Transform3d& pose) : _pose(pose) 
{}

void Shape::setPose(const Transform3d& pose)
{
    _pose = pose;
}

Transform3d Shape::getPose() const
{
    return _pose;
}
