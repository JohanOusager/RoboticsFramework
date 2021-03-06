#pragma once

#include "../math/Vector3d.hpp"
#include "../math/Pose.hpp"
#include "exception"

#include "memory"

class Cuboid
{
private:
    Vector3d _corners[8];
    std::shared_ptr<Pose> _centre;

    double _width;
    double _length;
    double _height;

    void updateCorners();

public:
    Cuboid(const std::shared_ptr<Pose> pose, const double &widht, const double &length, const double &height);

    ~Cuboid();

    Vector3d operator[](const uint &i) const;
    Cuboid& operator=(const Cuboid &otherCuboid);
    Cuboid operator*(const Pose &pose) const;
    Cuboid& operator*=(const Pose &pose);

    void setPose( std::shared_ptr<Pose> pose);
    std::shared_ptr<const Pose> getPose() const;

    //std::shared_ptr<Pose> pose() const;

};
