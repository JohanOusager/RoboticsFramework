#pragma once

#include "../math/Vector3d.hpp"
#include "../math/Quaternion.hpp"
#include <memory>

class Pose
{
private:
    /* data */
    Vector3d   _translation;
    Quaternion _rotation;
    

public:
    Pose(Vector3d translation, Quaternion rotation);
    Pose();
    ~Pose();

    Vector3d   translation() const;
    Quaternion rotation() const;

    void setTranslation(const Vector3d & translation);
    void setRotation(const Quaternion & rotation);

    static Pose IDENTITY();

    Pose& operator=(const Pose& otherPose);
    Pose operator*(const Pose& otherPose) const;
    Pose& operator*=(const Pose& otherPose);
};

