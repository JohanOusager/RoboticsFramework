#include "CollisionChecker.hpp"

using namespace math;
using namespace geometry;

bool CollisionChecker::isCollisionAABS(const Cuboid &firstCuboid, const Cuboid &secondCuboid)
{
    double distance = (firstCuboid.getPose().translation() - secondCuboid.getPose().translation()).magnitude();
    double radii_sum = ((firstCuboid.getPose().translation() - firstCuboid[0].getPosition()).magnitude() + (secondCuboid.getPose().translation() - secondCuboid[0].getPosition()).magnitude());
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
        if (math::lessThan(cuboidA.getPose().translation(), cuboidB.getPose().translation(), dimension))
        {
            double a_max = cuboidA[0].getPosition()[dimension];
            double b_min = cuboidB[0].getPosition()[dimension];
            for (uint i = 1; i < 8; i++)
            {
                if (a_max > b_min)
                {
                    break;
                }
                else
                {
                    a_max = std::max(a_max, cuboidA[i].getPosition()[dimension]);
                    b_min = std::min(b_min, cuboidB[i].getPosition()[dimension]);
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


bool CollisionChecker::isCollisionOBB(const Cuboid &cuboidA, const Cuboid &cuboidB)
{
    RotationMatrix rotationA = RotationMatrix::IDENTITY(); //math::toRotationMatrix(cuboidA.getPose().rotation());
    RotationMatrix rotationB = RotationMatrix::IDENTITY(); //math::toRotationMatrix(cuboidB.getPose().rotation());
    Vector3d planes[15] = {
        rotationA[0],
        rotationA[1],
        rotationA[2],

        rotationB[0],
        rotationB[1],
        rotationB[2],

        rotationA[0].cross(rotationB[0]),
        rotationA[1].cross(rotationB[1]),
        rotationA[2].cross(rotationB[2]),

        rotationA[0].cross(rotationB[0]),
        rotationA[1].cross(rotationB[1]),
        rotationA[2].cross(rotationB[2]),

        rotationA[0].cross(rotationB[0]),
        rotationA[1].cross(rotationB[1]),
        rotationA[2].cross(rotationB[2])
    };

    Vector3d halfDimensionsA = (cuboidA[0].getPosition() - cuboidA.getPose().translation()).abs()/2.0;
    Vector3d halfDimensionsB = (cuboidB[0].getPosition() - cuboidB.getPose().translation()).abs()/2.0;
    Vector3d distance = cuboidA.getPose().translation() - cuboidB.getPose().translation();

    if ((halfDimensionsA.dot(planes[0])))
    for (uint p = 0; p < 15; p++)
    {
        if ((halfDimensionsA.dot(planes[p])) + (halfDimensionsB.dot(planes[p])) < (distance.dot(planes[p])))
            return false;
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
    //else if (isCollisionOBB(firstBox, secondBox) == false)
    //    return false;
    else
        return true;
}