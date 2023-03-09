#pragma once

#include "GlutSimulation.hpp"
#include "math/Math.hpp"

class BoxPoseSimulation : public GlutSimulation
{
    public:
    BoxPoseSimulation();
    void normalKey(unsigned char key, int x, int y) override;
};