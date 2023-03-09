#include "../include/simulation/BoxCollisionSimulation.hpp"

#include "math/Transform3d.hpp"
#include "math/Vector3d.hpp"
#include "math/AxisAngle.hpp"
#include "math/Transform3d.hpp"
#include "math/Quaternion.hpp"

#include "geometry/Cuboid.hpp"

#include <memory>
#include <cmath>


int main(int argc, char** argv)
{
  BoxCollisionSimulation sim;
  Transform3d pose = Transform3d(Vector3d(0.5, 0.5, 0.5), Quaternion::IDENTITY());
  std::shared_ptr<Cuboid> moving_cube = std::make_shared<Cuboid>(pose, 1.0, 1.0, 1.0);
  std::shared_ptr<Cuboid> static_cube = std::make_shared<Cuboid>(pose, 1.0, 1.0, 1.0);
  sim.addCuboid(moving_cube);
  sim.addCuboid(static_cube);
  sim.run(argc, argv);
  
  return 0;
}
