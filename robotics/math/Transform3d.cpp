#include "math/Transform3d.hpp"

using namespace math;

Transform3d::Transform3d(Vector3d translation, Quaternion rotation)
{
    _translation = translation;
    _rotation = rotation;
}

Transform3d::Transform3d()
{
}

Transform3d::~Transform3d()
{
}

Vector3d Transform3d::translation() const
{
    return _translation;
}

Quaternion Transform3d::rotation() const
{
    return _rotation;
}

void Transform3d::setTranslation(const Vector3d &translation)
{
    _translation = translation;
}

void Transform3d::setRotation(const Quaternion &rotation)
{
    _rotation = rotation;
}

Transform3d Transform3d::IDENTITY()
{
    return Transform3d(Vector3d::ZERO(), Quaternion::IDENTITY());
}


Transform3d& Transform3d::operator=(const Transform3d& otherPose)
{
    _rotation = otherPose._rotation;
    _translation = otherPose._translation;
    return *this;
}

Transform3d Transform3d::operator*(const Transform3d& otherPose) const
{
    return Transform3d(
        _translation + otherPose._translation * _rotation, 
        _rotation * otherPose._rotation
    );
}

Transform3d& Transform3d::operator*=(const Transform3d& otherPose)
{
    *this = *this *otherPose;
    return *this;    
}