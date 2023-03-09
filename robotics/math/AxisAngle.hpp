#pragma once

#include "math/Vector3d.hpp"

namespace math
{

    class AxisAngle
    {
    private:
        /* data */
        double _data[4];

    public:
        AxisAngle(const double &angle, const double &ax, const double &ay, const double &az);
        AxisAngle(const double &angle, const Vector3d &axis);
        AxisAngle();
        ~AxisAngle();

        double getAngle() const;
        Vector3d getAxis() const;
    };

}