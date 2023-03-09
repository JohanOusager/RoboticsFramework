#include "simulation/GlutSimulationWrapper.hpp"

GlutSimulationWrapper::GlutSimulationWrapper()
{
}

void GlutSimulationWrapper::run(int argc, char *argv[])
{
  glut_simulation_wrapper = this;

  glutInit(&argc, argv);
  glutInitWindowSize(glut_simulation_wrapper->_windowWidth, glut_simulation_wrapper->_windowHeight);
  glutCreateWindow(glut_simulation_wrapper->_name.c_str());

  glutDisplayFunc(glut_simulation_wrapper->displayWrapper);
  glutReshapeFunc(glut_simulation_wrapper->reshapeWrapper);
  glutKeyboardFunc(glut_simulation_wrapper->normalKeyWrapper);
  glutSpecialFunc(glut_simulation_wrapper->specialKeyWrapper);

  glutCreateMenu(glut_simulation_wrapper->menuWrapper);
  glutAddMenuEntry(glut_simulation_wrapper->_menuEntry.first.c_str(), glut_simulation_wrapper->_menuEntry.second);
  glutAttachMenu(glut_simulation_wrapper->_menuBinding);

  glutMainLoop();
}

void GlutSimulationWrapper::setInstance()
{
  glut_simulation_wrapper = this;
}

void GlutSimulationWrapper::setWindowSize(const uint &width, const uint &height)
{
  _windowWidth = width;
  _windowHeight = height;
}

void GlutSimulationWrapper::setName(std::string name)
{
  _name = name;
}

void GlutSimulationWrapper::setOrthogonalProjection(const double& left, const double& right, const double& bottom, const double& top, const double& near, const double& far)
{
  _projection[0] = left;
  _projection[1] = right;

  _projection[2] = bottom;
  _projection[3] = top;

  _projection[4] = near;
  _projection[5] = far;
}


void GlutSimulationWrapper::setMenuEntry(const std::string &menuLabel, const int &menuKey)
{
  _menuEntry = std::pair<std::string, int>(menuLabel, menuKey);
}

void GlutSimulationWrapper::setMenuBinding(const int &menuBinding)
{
  _menuBinding = menuBinding;
}

// Virtual functions

void GlutSimulationWrapper::display()
{
  // Hard coded 3d frame
  double len = 2.0;
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3d(0, 0, 0);
  glVertex3d(len, 0, 0);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3d(0, 0, 0);
  glVertex3d(0, len, 0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3d(0, 0, 0);
  glVertex3d(0, 0, len);
  glEnd();
}

void GlutSimulationWrapper::reshape(int width, int height)
{

  double w2h = (height > 0) ? (double)width / height : 1;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(_projection[0] * w2h, _projection[1] * w2h, _projection[2], _projection[3], _projection[4], _projection[5]);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glutPostRedisplay();
}

void GlutSimulationWrapper::normalKey(unsigned char key, int x, int y)
{
  std::cout << "Pressed key " << key << std::endl;
}

void GlutSimulationWrapper::specialKey(int key, int x, int y)
{
  std::cout << "Pressed special key " << key << std::endl;
}

void GlutSimulationWrapper::menu(int value) {}

// Wrapper functions

void GlutSimulationWrapper::displayWrapper()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glut_simulation_wrapper->display();
  
  glFlush();
  glutSwapBuffers();
}

void GlutSimulationWrapper::reshapeWrapper(int width, int height)
{
  glut_simulation_wrapper->reshape(width, height);
}

void GlutSimulationWrapper::normalKeyWrapper(unsigned char key, int x, int y)
{
  glut_simulation_wrapper->normalKey(key, x, y);
}

void GlutSimulationWrapper::specialKeyWrapper(int key, int x, int y)
{
  glut_simulation_wrapper->specialKey(key, x, y);
}

void GlutSimulationWrapper::menuWrapper(int value)
{
  glut_simulation_wrapper->menu(value);
}