#include "Vector3d.hpp"

using namespace math;

Vector3d::Vector3d(const double &x, const double &y, const double &z)
    : _data{x, y, z}
{
}

Vector3d::Vector3d()
{
}

Vector3d::~Vector3d()
{
}

Vector3d Vector3d::ZERO()
{
    return Vector3d(0.0, 0.0, 0.0);
}

Vector3d& Vector3d::operator=(const Vector3d &rhs)
{
    _data[0] = rhs[0];
    _data[1] = rhs[1];
    _data[2] = rhs[2];

    return *this;
}

bool Vector3d::operator==(const Vector3d &rhs) const
{
    return ((*this - rhs).magnitude() <= _precision);
    return (_data[0] - rhs._data[0] && _data[1] == rhs._data[1] && _data[2] == rhs._data[2]);
}


double Vector3d::operator[](const int &i) const
{
    if (i < 0 || i > 2)
        throw std::runtime_error(
            (std::string("Vector3d can only be indexed in the [0-2] range. Tried ") + std::to_string(i)));

    return _data[i];
}

Vector3d Vector3d::operator-(const Vector3d &rhs) const
{
    return Vector3d(
        _data[0] - rhs[0],
        _data[1] - rhs[1],
        _data[2] - rhs[2]);
}

Vector3d &Vector3d::operator-=(const Vector3d &rhs)
{
    *this = *this - rhs;
    return *this;
}

Vector3d Vector3d::operator+(const Vector3d &rhs) const
{
    return Vector3d(
        _data[0] + rhs[0],
        _data[1] + rhs[1],
        _data[2] + rhs[2]);
}

Vector3d& Vector3d::operator+=(const Vector3d &rhs)
{
    *this = *this + rhs;
    return *this;
}

Vector3d Vector3d::operator*(const Quaternion &quaternion) const
{
    Quaternion vector3d_quaternion(0.0, _data[0],  _data[1], _data[2]);
    Quaternion result = (quaternion * vector3d_quaternion) * quaternion.conjugate();
    return Vector3d(result[1], result[2], result[3]);
}

Vector3d& Vector3d::operator*=(const Quaternion &quaternion)
{
    return *this = *this * quaternion;
}

Vector3d Vector3d::operator*(const double& scalar) const
{
    return Vector3d(_data[0]*scalar, _data[1]*scalar, _data[2]*scalar);
}

Vector3d& Vector3d::operator*=(const double& scalar)
{
    return *this = *this * scalar;
}

Vector3d Vector3d::operator/(const double& scalar) const
{
    return Vector3d(_data[0]*1.0/scalar, _data[1]*1.0/scalar, _data[2]*1.0/scalar);
}

Vector3d& Vector3d::operator/=(const double& scalar)
{
    return *this = *this / scalar;
}

// void Vector3d::normalize()
//{
// }

double Vector3d::dot(const Vector3d& rhs) const
{
    return (_data[0] * rhs._data[0]) + (_data[1] * rhs._data[1]) + (_data[2] * rhs._data[2]);
}

Vector3d Vector3d::cross(const Vector3d& rhs) const
{
    return Vector3d(_data[1]*rhs[2] - _data[2]*rhs[1],
                    _data[2]*rhs[0] - _data[0]*rhs[2], 
                    _data[0]*rhs[1] - _data[1]*rhs[0]
                    );
}

Vector3d Vector3d::abs() const
{
    return Vector3d(std::abs(_data[0]), std::abs(_data[1]), std::abs(_data[2]));
}
    
double Vector3d::magnitude() const
{
    return std::sqrt(std::pow(_data[0], 2.0) + std::pow(_data[1], 2.0) + std::pow(_data[2], 2.0));
}