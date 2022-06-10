#include "../include/simulation/GlutSimulation.hpp"

#include "math/Pose.hpp"
#include "math/Vector3d.hpp"
#include "math/AxisAngle.hpp"
#include "math/Pose.hpp"
#include "math/Quaternion.hpp"

#include "geometry/Cuboid.hpp"

#include <memory>


int main(int argc, char** argv)
{
	GlutSimulation framework;	
    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Cuboid> cube = std::make_shared<Cuboid>(std::make_shared<Pose>(Pose::IDENTITY()), i*0.25, i*0.25, i*0.25);
        framework.addCuboid(cube);
    }
	framework.startFramework(argc, argv);
    return 0;
}
