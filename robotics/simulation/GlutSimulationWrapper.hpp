#pragma once

#include <string>
#include <utility> 
#include <iostream>

/* OpenGL and friends */
#ifdef USEGLEW
#include <GL/glew.h>
#endif
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


namespace simulation
{

class GlutSimulationWrapper;
static GlutSimulationWrapper* glut_simulation_wrapper;

class GlutSimulationWrapper
{
    private:
    uint _windowWidth = 480;
    uint _windowHeight = 360;
    double _projection[6] = {-10.0, 10.0, -10.0, 10.0, -10.0, 10.0};
    std::string _name = "GLUT Simulation";


    std::pair<std::string, int> _menuEntry;
    int _menuBinding;

    public:

    // Main
    GlutSimulationWrapper();

    void run(int argc, char *argv[]);


    // Setters

    void setInstance();

    void setWindowSize(const uint& width, const uint& height);

    void setName(std::string name);

    void setOrthogonalProjection(const double& left, const double& right, const double& bottom, const double& top, const double& near, const double& far);

    void setMenuEntry(const std::string&  menuLabel, const int&  menuKey);

    void setMenuBinding(const int& menuBinding);

    // Getters 


    // Virtual functions

    virtual void display();

    virtual void reshape(int width, int height);

    virtual void normalKey(unsigned char key, int x, int y);

    virtual void specialKey(int key, int x, int y);

    virtual void menu(int value);



    // Wrapper functions

    static void displayWrapper();
    
    static void reshapeWrapper(int width, int height);


    static void normalKeyWrapper(unsigned char key, int x, int y);

    static void specialKeyWrapper(int key, int x, int y);

    static void menuWrapper(int value);
    
/*
void GlutSimulationWrapper::run(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(_windowWidth, _windowHeight);
    glutCreateWindow(_name);

    glutDisplayFunc(displayWrapper);
    glutReshapeFunc(reshapeWrapper);
    glutKeyboardFunc(windowKeyWrapper);
    glutSpecialFunc(windowSpecialWrapper);

    glutCreateMenu(windowMenuWrapper);
    glutAddMenuEntry(menuEntryWrapper);
}

int main(int argc, char *argv[])
{
  GlutSimulationWrapper sim;
  GlutSimulationWrapper.run(argc, argv);
  
  return 0;
}
*/
};

}