#include "simulation/GlutSimulation.hpp"

// Constructors and destructors       //

GlutSimulation::GlutSimulation()
{
}

GlutSimulation::~GlutSimulation()
{
}


// GLUT overrides                     //

void GlutSimulation::display(float dTime)
{
		
		static int frame = 0;
		std::cout << "GlutFramework Display: Frame: " << frame << ", dt(sec): " << dTime << ", Position: " << position << std::endl;
		++frame;
		

		// DEMO: Create a teapot and move it back and forth on the x-axis
		glTranslatef(position, 0.0f, 0.0f);
		glutSolidTeapot(2.5); 
		if(position > 4 && direction > 0) {
			direction = -1.0 / FRAME_TIME;
		} else if(position < -4 && direction < 0) {
			direction = 1.0 / FRAME_TIME;
		}		
		position += direction;

  /*
  for (int ci = 0; ci < _cuboids.size(); ci++)
  {
    drawCuboid(*_cuboids[ci]);
  }
  for (int li = 0; li < _lines.size(); li++)
  {
    drawLine(*_lines[li].first, *_lines[li].second);
  }

	glutSolidTeapot(2.5); 
  */

}

// Drawing functions                  //

void GlutSimulation::drawLine(const Vector3d& start, const Vector3d& end)
{
  glBegin(GL_LINE);
  //glColor3f(1, 0, 0);
  glVertex3f(start[0], start[1], start[2]);
  glVertex3f(end[0], end[1], end[2]);
  glEnd();
}

void GlutSimulation::drawCuboid(const Cuboid &cuboid)
{
  std::cout << "Cube drawn!" << std::endl;
  for (int i = 0; i < 8; i++)
  {
    drawLine(cuboid[i], cuboid[(i+1)%8]);
    std::cout << cuboid[i][0] << "   " << cuboid[i][1] << "   " << cuboid[i][2]  <<  " Drawing line " << i << std::endl;
  }
}

// Add element to draw

void GlutSimulation::addLine(const std::shared_ptr<Vector3d> start, const std::shared_ptr<Vector3d> end)
{
  _lines.push_back(std::pair<std::shared_ptr<Vector3d>, std::shared_ptr<Vector3d>>(start, end));
}
    
void GlutSimulation::addCuboid(const std::shared_ptr<Cuboid> cuboid)
{
  std::cout << "Cube added!" << std::endl;
  _cuboids.push_back(cuboid);
}

