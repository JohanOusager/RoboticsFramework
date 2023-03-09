#pragma once

#include "math/Vector3d.hpp"

#include <array>

namespace math
{

    class RotationMatrix
    {

        RotationMatrix(/* args */);
        RotationMatrix(const Vector3d &row1, const Vector3d &row2, const Vector3d &row3);

        RotationMatrix(
            const double &row1col1, const double &row1col2, const double &row1col3,
            const double &row2col1, const double &row2col2, const double &row2col3,
            const double &row3col1, const double &row3col2, const double &row3col3);

        RotationMatrix IDENTITY();

        ~RotationMatrix();

        Vector3d &operator[](const uint idx);

        Vector3d operator[](const uint idx) const;

        private:
        std::array<Vector3d, 3> _data;
    };

}