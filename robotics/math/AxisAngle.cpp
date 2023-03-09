#include "math/AxisAngle.hpp"

using namespace math;

AxisAngle::AxisAngle(const double &angle, const double & ax, const double & ay,const double & az)
{
    AxisAngle(angle, Vector3d(ax, ay, az));
}
    
AxisAngle::AxisAngle(const double &angle, const Vector3d & axis)
{
    _data[0] = angle;
    //axis.normalize();
    _data[1] = axis[0];
    _data[2] = axis[1];
    _data[3] = axis[2];
}

AxisAngle::AxisAngle()
{
}
    
AxisAngle::~AxisAngle()
{
}

double AxisAngle::getAngle() const
{
    return _data[0];
}
   
Vector3d AxisAngle::getAxis() const
{
    return Vector3d(_data[1], _data[2], _data[3]);
}
