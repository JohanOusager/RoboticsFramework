#include "simulation/GlutSimulation.hpp"

using namespace math;
using namespace geometry;
using namespace simulation;

// Constructors and destructors       //
GlutSimulation::GlutSimulation()
{
}

GlutSimulation::~GlutSimulation()
{
}

// GLUT overrides                     //

void GlutSimulation::display()
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
    drawCuboid(*_cuboids[ci]);
  }
  for (int li = 0; li < _lines.size(); li++)
  {
    drawLine(*_lines[li].first, *_lines[li].second);
  }
}

void GlutSimulation::specialKey(int key, int x, int y)
{
  /*  Right arrow key - increase azimuth by 5 degrees */
  if (key == GLUT_KEY_RIGHT)
  {
    th += 5;
    // std::cout << "pressed right key " << key << std::endl;
  }
  /*  Left arrow key - decrease azimuth by 5 degrees */
  else if (key == GLUT_KEY_LEFT)
    th -= 5;
  /*  Up arrow key - increase elevation by 5 degrees */
  else if (key == GLUT_KEY_UP)
    ph += 5;
  /*  Down arrow key - decrease elevation by 5 degrees */
  else if (key == GLUT_KEY_DOWN)
    ph -= 5;

  /*  Keep angles to +/-360 degrees */
  th %= 360;
  ph %= 360;

  GlutSimulationWrapper::specialKey(key, x, y);
  glutPostRedisplay();
}

// Drawing functions                  //

void GlutSimulation::drawLine(const Vector3d &start, const Vector3d &end, const Color &color)
{
  glBegin(GL_LINES);
  glColor3f(color.rgb[0], color.rgb[1], color.rgb[2]);
  glVertex3d(start[0], start[1], start[2]);
  glVertex3d(end[0], end[1], end[2]);
  //std::cout << "Line " << start[0] << " " << start[1] << " " << start[2] << "    " << end[0] << " " << end[1] << " " << end[2] << std::endl;
  glEnd();
}

void GlutSimulation::drawCuboid(const Cuboid &cuboid, const Color &color)
{
  // std::cout << "Cube drawn!" << std::endl;
  for (int i = 0; i < 8; i++)
  {
    drawLine(cuboid[0].getPosition(), cuboid[1].getPosition(), color);
    drawLine(cuboid[0].getPosition(), cuboid[2].getPosition(), color);

    drawLine(cuboid[1].getPosition(), cuboid[3].getPosition(), color);
    drawLine(cuboid[1].getPosition(), cuboid[7].getPosition(), color);

    drawLine(cuboid[2].getPosition(), cuboid[3].getPosition(), color);
    drawLine(cuboid[2].getPosition(), cuboid[4].getPosition(), color);

    drawLine(cuboid[4].getPosition(), cuboid[5].getPosition(), color);
    drawLine(cuboid[4].getPosition(), cuboid[6].getPosition(), color);

    drawLine(cuboid[5].getPosition(), cuboid[3].getPosition(), color);
    drawLine(cuboid[5].getPosition(), cuboid[7].getPosition(), color);

    drawLine(cuboid[6].getPosition(), cuboid[7].getPosition(), color);
    drawLine(cuboid[6].getPosition(), cuboid[0].getPosition(), color);
  }
}

// Add element to draw

void GlutSimulation::addLine(const std::shared_ptr<Vector3d> start, const std::shared_ptr<Vector3d> end)
{
  // std::cout << "Line added!" << std::endl;
  _lines.push_back(std::pair<std::shared_ptr<Vector3d>, std::shared_ptr<Vector3d>>(start, end));
}

void GlutSimulation::addCuboid(const std::shared_ptr<Cuboid> cuboid)
{
  // std::cout << "Cube added!" << std::endl;
  _cuboids.push_back(cuboid);
}
