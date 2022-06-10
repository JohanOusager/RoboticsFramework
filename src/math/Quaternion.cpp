#include "math/Quaternion.hpp"
#include <cmath>

Quaternion::Quaternion(double w, double xi, double yj, double zk) : _data{w, xi, yj, zk}
{
}

/*
Quaternion::Quaternion(const AxisAngle &axis_angle_rotation)
{
    double angle = axis_angle_rotation.getAngle();
    Vector3d axis = axis_angle_rotation.getAxis();

    _data[0] = std::cos(angle / 2.0);

    _data[1] = axis[0] * sin(angle / 2.0);
    _data[2] = axis[1] * sin(angle / 2.0);
    _data[3] = axis[2] * sin(angle / 2.0);
}
*/


Quaternion::Quaternion()
{
}

Quaternion::~Quaternion()
{
}

double Quaternion::operator[](const uint &i) const
{
    if (i < 0 || i > 3)
        throw std::runtime_error(
            (std::string("Quaternion can only be indexed in the [0-3] range. Tried ") 
            + std::to_string(i)));
    return _data[i];
}

Quaternion& Quaternion::operator=(const Quaternion& otherQuaternion)
{
    _data[0] = otherQuaternion._data[0];
    _data[1] = otherQuaternion._data[1];
    _data[2] = otherQuaternion._data[2];
    _data[3] = otherQuaternion._data[3];
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion& otherQuaternion) const
{
    return Quaternion(
        _data[0] * otherQuaternion._data[0] - _data[1] * otherQuaternion._data[1] - _data[2] * otherQuaternion._data[2] - _data[3] * otherQuaternion._data[3],
        _data[0] * otherQuaternion._data[1] + _data[1] * otherQuaternion._data[0] - _data[2] * otherQuaternion._data[3] + _data[3] * otherQuaternion._data[2],
        _data[0] * otherQuaternion._data[2] + _data[1] * otherQuaternion._data[3] + _data[2] * otherQuaternion._data[0] - _data[3] * otherQuaternion._data[1],
        _data[0] * otherQuaternion._data[3] - _data[1] * otherQuaternion._data[2] + _data[2] * otherQuaternion._data[1] + _data[3] * otherQuaternion._data[0]);
}

Quaternion& Quaternion::operator*=(const Quaternion& otherQuaternion)
{
    *this = *this * otherQuaternion;
    
}

Quaternion Quaternion::conjugate() const
{
    return Quaternion(_data[0], -_data[1], -_data[2], -_data[3]);
}


Quaternion Quaternion::IDENTITY()
{
    return Quaternion(1.0, 0.0, 0.0, 0.0);
}