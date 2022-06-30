#include "CollisionChecker.hpp"

bool CollisionChecker::isCollisionAABS(const Cuboid &firstCuboid, const Cuboid &secondCuboid)
{
    double distance = (firstCuboid.getPose()->translation() - secondCuboid.getPose()->translation()).magnitude();
    double radii_sum = ((firstCuboid.getPose()->translation() - firstCuboid[0]) + (secondCuboid.getPose()->translation() - secondCuboid[0]));
    if (distance <= radii_sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CollisionChecker::isCollisionAABB(const Cuboid &cuboidA, const Cuboid &cuboidB)
{
    double dimension = 0;
    for (uint dimension = 0; dimension < 3; dimension++)
    {
        if (math::lessThan(cuboidA.getPose()->translation(), cuboidB.getPose()->translation(), dimension))
        {
            double a_max = cuboidA[0][dimension];
            double b_min = cuboidB[0][dimension];
            for (uint i = 1; i < 8; i++)
            {
                if (a_max > b_min)
                {
                    break;
                }
                else
                {
                    a_max = std::max(a_max, cuboidA[i][dimension]);
                    b_min = std::min(b_min, cuboidB[i][dimension]);
                }
            }
            if (a_max < b_min)
            {
                return false;
            }
        }
    }
    return true;
}

CollisionChecker::CollisionChecker()
{
}

CollisionChecker::~CollisionChecker()
{
}

bool CollisionChecker::isCollision(const Cuboid &firstBox, const Cuboid &secondBox)
{
    if (isCollisionAABS(firstBox, secondBox) == false)
        return false;
    else if (isCollisionAABB(firstBox, secondBox) == false)
        return false;
    else
        return true;
}