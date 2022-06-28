#pragma once
#include "math.h"
#include "AxisAngle.hpp"

namespace math
{
    inline double pi()
    {
        return 3.14159265359;
    }

    inline double toRadians(const double &degrees)
    {
        return degrees / 180.0 * pi();
    }

    inline double toDegrees(const double &radians)
    {
        return radians / pi() * 180.0;
    }

    inline Quaternion toQuaternion(const AxisAngle &axis_angle)
    {
        double angle = axis_angle.getAngle();
        Vector3d axis = axis_angle.getAxis();

        return Quaternion(
            std::cos(axis_angle.getAngle() / 2.0),
            axis_angle.getAxis()[0] * sin(axis_angle.getAngle() / 2.0),
            axis_angle.getAxis()[1] * sin(axis_angle.getAngle() / 2.0),
            axis_angle.getAxis()[2] * sin(axis_angle.getAngle() / 2.0));
    }

    inline AxisAngle toAxisAngle(const Quaternion quaternion)
    {
        std::cout << "toAxisAngle not implemented!" << std::endl;
        return AxisAngle(0.0, Vector3d::ZERO());
    }
};