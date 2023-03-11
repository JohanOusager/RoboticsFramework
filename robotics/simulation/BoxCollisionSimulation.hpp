#pragma once
#pragma once

#include "geometry/CollisionChecker.hpp"

#include "simulation/BoxPoseSimulation.hpp"

namespace simulation
{
  class BoxCollisionSimulation : public BoxPoseSimulation
  {
    public:
    
    BoxCollisionSimulation();

    void display();
  };
} // namespace simulation