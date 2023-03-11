#pragma once

#include "math/Transform3d.hpp"

namespace geometry
{
    class Shape
    {
    public:
        Shape(const math::Transform3d& pose);

        void setPose(const math::Transform3d& pose);

        math::Transform3d getPose() const;

    protected:
        math::Transform3d _pose;
    };
}