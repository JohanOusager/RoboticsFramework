#pragma once

#include <math.h>

#include "math/Math.hpp"
#include "math/RotationMatrix.hpp"

#include "geometry/Cuboid.hpp"

 #include<algorithm>

namespace geometry
{

class CollisionChecker
{
    private:

    /**
     * @brief Collision check using Axis Aligned Bounding Spheres.
     * 
     * @param firstBox 
     * @param secondBox 
     * @return Boolean indicating if a collision is possible.
     */
    bool isCollisionAABS(const Cuboid& firstBox, const Cuboid& secondBox);

    /**
     * @brief Collision check using Axis Aligned Bouding Boxes.
     * 
     * @param firstBox 
     * @param secondBox 
     * @return Boolean indicating is a collision is possible.
     */
    bool isCollisionAABB(const Cuboid& firstBox, const Cuboid& secondBox);

    /**
     * @brief Collision check using Oriented Bouding Boxes.
     * 
     * @param firstBox 
     * @param secondBox 
     * @return Boolean indicating is a collision is possible.
     */
    bool isCollisionOBB(const Cuboid& firstBox, const Cuboid& secondBox);

    public:

    CollisionChecker();
    ~CollisionChecker();

    bool isCollision(const Cuboid& firstBox, const Cuboid& secondBox);
};

}