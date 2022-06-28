#include "../include/simulation/BoxPoseSimulation.hpp"

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
  BoxPoseSimulation sim;
  sim.run(argc, argv);
  
  return 0;
}
