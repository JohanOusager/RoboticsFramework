#pragma once
#include <iostream>
#include <GL/glut.h>

#include "geometry/Cuboid.hpp"
#include "GLUT-Object-Oriented-Framework/src/GlutFramework.h"

class GlutSimulation : public glutFramework::GlutFramework
{
private:
    std::vector<std::pair<std::shared_ptr<Vector3d>, std::shared_ptr<Vector3d>>> _lines;
    std::vector<std::shared_ptr<Cuboid>> _cuboids;

    void drawLine(const Vector3d& start, const Vector3d& end);
    void drawCuboid(const Cuboid & cuboid);
    virtual void display(float dTime) override;

    /* data */
public:
    GlutSimulation();
    ~GlutSimulation();

    void addLine(const std::shared_ptr<Vector3d> start, const std::shared_ptr<Vector3d> end);
    void addCuboid(const std::shared_ptr<Cuboid> cuboid);
};
