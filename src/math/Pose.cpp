
#include "math/Pose.hpp"

Pose::Pose(Vector3d translation, Quaternion rotation)
{
    _translation = translation;
    _rotation = rotation;
}

Pose::Pose()
{
}

Pose::~Pose()
{
}

Vector3d Pose::translation() const
{
    return _translation;
}

Quaternion Pose::rotation() const
{
    return _rotation;
}

void Pose::setTranslation(const Vector3d &translation)
{
    _translation = translation;
}

void Pose::setRotation(const Quaternion &rotation)
{
    _rotation = rotation;
}

Pose Pose::IDENTITY()
{
    return Pose(Vector3d::ZERO(), Quaternion::IDENTITY());
}


Pose& Pose::operator=(const Pose& otherPose)
{
    _rotation = otherPose._rotation;
    _translation = otherPose._translation;
    return *this;
}

Pose Pose::operator*(const Pose& otherPose) const
{
    return Pose(
        _translation + otherPose._translation * _rotation, 
        _rotation * otherPose._rotation
    );
}

Pose& Pose::operator*=(const Pose& otherPose)
{
    *this = *this *otherPose;
    return *this;    
}