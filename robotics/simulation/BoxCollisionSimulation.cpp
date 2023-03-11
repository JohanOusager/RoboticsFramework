#include "simulation/BoxCollisionSimulation.hpp"

using namespace math;
using namespace geometry;
using namespace simulation;

BoxCollisionSimulation::BoxCollisionSimulation()
{
}

void BoxCollisionSimulation::display()
{
  /*  Set View Angle */
  glRotated(ph, 1, 0, 0);
  glRotated(th, 0, 1, 0);

  double len = 2.5;
  drawLine(Vector3d(0.0, 0.0, 0.0), Vector3d(len * 1.0, 0.0, 0.0), Color(1.0, 0.0, 0.0));
  drawLine(Vector3d(0.0, 0.0, 0.0), Vector3d(0.0, len * 1.0, 0.0), Color(0.0, 1.0, 0.0));
  drawLine(Vector3d(0.0, 0.0, 0.0), Vector3d(0.0, 0.0, len * 1.0), Color(0.0, 0.0, 1.0));

  for (int ci = 0; ci < _cuboids.size(); ci++)
  {
    CollisionChecker col_checker;
    bool collision = false;
    for (int ck = 0; ck < _cuboids.size(); ck++)
    {
        if (ci == ck)
            continue;
        if (col_checker.isCollision(*_cuboids[ci], *_cuboids[ck]))
        {
            collision = true;
            break;
        }
    }
    if (collision)
        drawCuboid(*_cuboids[ci], {1, 0, 0});
    else
        drawCuboid(*_cuboids[ci], {0, 1, 0});
 
  }
  for (int li = 0; li < _lines.size(); li++)
  {
    drawLine(*_lines[li].first, *_lines[li].second);
  }
}
