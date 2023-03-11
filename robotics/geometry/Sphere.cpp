#include "geometry/Sphere.hpp"

using namespace geometry;
using namespace math;

Sphere::Sphere(Vector3d centroid, double radius) : Shape(Transform3d(centroid, Quaternion::IDENTITY())),
                                                   _radius(radius)
{
}

Sphere::Sphere(math::Transform3d centroid, double radius) : Shape(centroid),
                                                      _radius(radius)
{
}

double Sphere::radius() const
{
    return _radius;
}

void Sphere::setRadius(const double &newRadius)
{
    _radius = newRadius;
}