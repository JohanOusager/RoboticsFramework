#pragma once

#include "GlutSimulation.hpp"
#include "math/Transform3d.hpp"
#include "math/Math.hpp"

namespace simulation
{

class BoxPoseSimulation : public GlutSimulation
{
    public:
    BoxPoseSimulation();
    void normalKey(unsigned char key, int x, int y) override;
};

}