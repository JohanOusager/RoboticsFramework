#pragma once

#include <exception>
#include <memory>

#include "geometry/Shape.hpp"
#include "geometry/Vertex3d.hpp"

#include "math/Vector3d.hpp"
#include "math/Transform3d.hpp"

namespace geometry
{
    class Cuboid : public Shape
    {
    private:
        Vertex3d _corners[8];
        //std::shared_ptr<math::Transform3d> _centre;

        double _width;
        double _length;
        double _height;

        void updateCorners();

    public:
        Cuboid(const math::Transform3d& pose, const double &widht, const double &length, const double &height);

        ~Cuboid();

        Vertex3d operator[](const uint &i) const;
        Cuboid &operator=(const Cuboid &otherCuboid);
        Cuboid operator*(const math::Transform3d &pose) const;
        Cuboid &operator*=(const math::Transform3d &pose);

        void setPose(std::shared_ptr<math::Transform3d> pose);
        //std::shared_ptr<const math::Transform3d> getPose() const;

        // std::shared_ptr<Pose> pose() const;
    };
}
