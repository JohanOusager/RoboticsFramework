#include "math/RotationMatrix.hpp"

using namespace math;

RotationMatrix::RotationMatrix(/* args */)
{
}

RotationMatrix::RotationMatrix(const Vector3d &row1, const Vector3d &row2, const Vector3d &row3)
{
    _data[0] = row1;
    _data[1] = row2;
    _data[2] = row3;
}

RotationMatrix::RotationMatrix(
    const double &row1col1, const double &row1col2, const double &row1col3,
    const double &row2col1, const double &row2col2, const double &row2col3,
    const double &row3col1, const double &row3col2, const double &row3col3)
{
    _data[0] = Vector3d(row1col1, row1col2, row1col3);
    _data[1] = Vector3d(row2col1, row2col2, row2col3);
    _data[2] = Vector3d(row3col1, row3col2, row3col3);
}

RotationMatrix RotationMatrix::IDENTITY()
{
    return RotationMatrix(Vector3d(1, 0, 0), Vector3d(0, 1, 0), Vector3d(0, 0, 1));
}

RotationMatrix::~RotationMatrix()
{
}

Vector3d& RotationMatrix::operator[](const uint idx)
{
    return _data[idx];
}

Vector3d RotationMatrix::operator[](const uint idx) const
{
    return _data[idx];
}