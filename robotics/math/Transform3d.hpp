#pragma once

#include "math/Quaternion.hpp"
#include "math/Vector3d.hpp"

namespace math
{
    class Transform3d
    {
        public:

        Transform3d(Vector3d translation, Quaternion rotation);

        Transform3d();

        ~Transform3d();

        Vector3d translation() const;

        Quaternion rotation() const;

        void setTranslation(const Vector3d &translation);

        void setRotation(const Quaternion &rotation);

        static Transform3d IDENTITY();

        Transform3d& operator=(const Transform3d &otherPose);

        Transform3d operator*(const Transform3d &otherPose) const;

        Transform3d& operator*=(const Transform3d &otherPose);

        private:
        Vector3d _translation;
        Quaternion _rotation;
    };
} // namespace math