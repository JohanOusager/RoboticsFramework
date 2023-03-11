#pragma once

#include "geometry/Shape.hpp"

#include "math/Vector3d.hpp"
#include "math/Transform3d.hpp"

namespace geometry
{
    class Sphere : public Shape
    {
    public:
        Sphere(math::Vector3d centroid, double radius);

        Sphere(math::Transform3d centroid, double radius);

        double radius() const;

        void setRadius(const double &newRadius);

        private:
        double _radius;
    };
}