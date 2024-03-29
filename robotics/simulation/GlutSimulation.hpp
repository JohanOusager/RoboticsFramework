#pragma once
#include <iostream>
#include <vector>

#include "math/Vector3d.hpp"

#include "geometry/Cuboid.hpp"
#include "simulation/GlutSimulationWrapper.hpp"

namespace simulation
{

struct Color 
{
    GLfloat rgb[3] = {1.0, 1.0, 1.0};
    Color(double red, double green, double blue)
    {
        rgb[0] = red;
        rgb[1] = green;
        rgb[2] = blue;
    };
};


class GlutSimulation : public GlutSimulationWrapper
{
protected:
    std::vector<std::pair<std::shared_ptr<math::Vector3d>, std::shared_ptr<math::Vector3d>>> _lines;
    std::vector<std::shared_ptr<geometry::Cuboid>> _cuboids;

    void drawLine(const math::Vector3d& start, const math::Vector3d& end, const Color& color = {1.0, 1.0, 1.0});
    void drawCuboid(const geometry::Cuboid & cuboid, const Color& color = {1.0, 1.0, 1.0});

    virtual void display() override;
	virtual void specialKey( int key, int x, int y ) override;

    /*  Display view */
    int th = 0;  /* azimuth of view angle */
    int ph = 0;  /* elevation of view angle */

    /* data */
public:
    GlutSimulation();
    ~GlutSimulation();

    void addLine(const std::shared_ptr<math::Vector3d> start, const std::shared_ptr<math::Vector3d> end);
    void addCuboid(const std::shared_ptr<geometry::Cuboid> cuboid);
};

}