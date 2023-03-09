#pragma once

#include <string>
#include <stdexcept>
#include <cmath>

#include "math/Quaternion.hpp"

namespace math
{

    class Vector3d
    {
    private:
        double _data[3];
        const double _precision = 1.0e-4;

    public:
        Vector3d(const double &x, const double &y, const double &z);
        Vector3d();
        ~Vector3d();

        double operator[](const int &i) const;

        Vector3d &operator=(const Vector3d &rhs);
        bool operator==(const Vector3d &rhs) const;

        Vector3d operator-(const Vector3d &rhs) const;
        Vector3d &operator-=(const Vector3d &rhs);
        Vector3d operator+(const Vector3d &rhs) const;
        Vector3d &operator+=(const Vector3d &rhs);
        Vector3d operator/(const double &scalar) const;
        Vector3d &operator/=(const double &scalar);

        // Quaternion Operators
        Vector3d operator*(const Quaternion &quaternion) const;
        Vector3d &operator*=(const Quaternion &quaternion);

        // Scalar Operators
        Vector3d operator*(const double &scalar) const;
        Vector3d &operator*=(const double &scalar);

        static Vector3d ZERO();

        double dot(const Vector3d &rhs) const;
        Vector3d cross(const Vector3d &rhs) const;
        Vector3d abs() const;
        double magnitude() const;
    };

} // namespace math
