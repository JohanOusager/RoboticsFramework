#include "../include/simulation/GlutSimulationWrapper.hpp"
#include "../include/simulation/GlutSimulation.hpp"

#include "math/Pose.hpp"
#include "math/Vector3d.hpp"
#include "math/AxisAngle.hpp"
#include "math/Pose.hpp"
#include "math/Quaternion.hpp"

#include "geometry/Cuboid.hpp"

#include <memory>
#include <cmath>


int main(int argc, char** argv)
{
  GlutSimulation sim;
  std::shared_ptr<Pose> pose = std::make_shared<Pose>( Vector3d(0.5, 0.5, 0.5), Quaternion::IDENTITY());
  std::shared_ptr<Cuboid> cube = std::make_shared<Cuboid>(pose, 1.0, 1.0, 1.0);
  sim.addCuboid(cube);
  sim.run(argc, argv);
  
  return 0;
}

/*

int main(int argc, char** argv)
{

    GlutSimulation sim;
    //framework.startFramework(argc, argv);
    
    for (int i = 0; i < 10; i++)
    {
        std::shared_ptr<Cuboid> cube = std::make_shared<Cuboid>(std::make_shared<Pose>(Pose::IDENTITY()), std::pow(i,i)*0.25, std::pow(i,i)*0.25, std::pow(i,i)*0.25);
        sim.addCuboid(cube);
    }
    sim.run(argc, argv);
    return 0; 
}

*/