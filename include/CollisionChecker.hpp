#pragma once
#include "Cuboid.hpp"
#include "Math.hpp"
#include <math>

 #include<algorithm>

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

    public:

    CollisionChecker();
    ~CollisionChecker();

    bool isCollision(const Cuboid& firstBox, const Cuboid& secondBox);
};