#include "simulation/BoxPoseSimulation.hpp"

#include "math/Transform3d.hpp"
#include "math/Vector3d.hpp"
#include "math/AxisAngle.hpp"
#include "math/Quaternion.hpp"

#include "geometry/Cuboid.hpp"

#include <memory>
#include <cmath>


int main(int argc, char** argv)
{
  simulation::BoxPoseSimulation sim;
  math::Transform3d pose = math::Transform3d(math::Vector3d(0.5, 0.5, 0.5),  math::Quaternion::IDENTITY());
  std::shared_ptr<geometry::Cuboid> cube = std::make_shared<geometry::Cuboid>(pose, 1.0, 1.0, 1.0);
  sim.addCuboid(cube);
  sim.run(argc, argv);
  
  return 0;
}
