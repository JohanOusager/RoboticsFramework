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

class GlutSimulationWrapper;
static GlutSimulationWrapper* glut_simulation_wrapper;

class GlutSimulationWrapper
{
    private:
    uint _windowWidth;
    uint _windowHeight;
    std::string _name;


    std::pair<std::string, int> _menuEntry;
    int _menuBinding;

    /*  Display view */
    int th = 0;  /* azimuth of view angle */
    int ph = 0;  /* elevation of view angle */
    int dim = 10;

    public:

    // Main

    GlutSimulationWrapper();

    void run(int argc, char *argv[]);


    // Setters

    void setInstance();

    void setWindowSize(const uint& width, const uint& height);

    void setName(std::string name);

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