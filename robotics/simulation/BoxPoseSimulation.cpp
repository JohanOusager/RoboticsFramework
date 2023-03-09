#include "simulation/BoxPoseSimulation.hpp"

BoxPoseSimulation::BoxPoseSimulation()
{
    //addCuboid(std::make_shared<Cuboid>(std::make_shared<Transform3d>(Transform3d::IDENTITY()), 5.0, 10.0, 2.5));
}

void BoxPoseSimulation::normalKey(unsigned char key, int x, int y)
{

    double angle_step = math::toRadians(5.0);
    double translation_step = 0.5;
    switch (key)
    {
        //rotate
    case 'q':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(1.0, 0.0, 0.0)))); 
        break;
    case 'a':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(1.0, 0.0, 0.0)))); 
        break;
    case 'w':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(0.0, 1.0, 0.0)))); 
        break;
    case 's':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(0.0, 1.0, 0.0)))); 
        break;
    case 'e':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(0.0, 0.0, 1.0)))); 
        break;
    case 'd':
        *_cuboids[0] *= Transform3d(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(0.0, 0.0, 1.0)))); 
        break;
        
        //translate
    case 't':
        *_cuboids[0] *= Transform3d(Vector3d(translation_step, 0.0, 0.0), Quaternion::IDENTITY()); 
        break;
    case 'g':
        *_cuboids[0] *= Transform3d(Vector3d(-translation_step, 0.0, 0.0), Quaternion::IDENTITY()); 
        break;
    case 'y':
        *_cuboids[0] *= Transform3d(Vector3d(0.0, translation_step, 0.0), Quaternion::IDENTITY()); 
        break;
    case 'h':
        *_cuboids[0] *= Transform3d(Vector3d(0.0, -translation_step, 0.0), Quaternion::IDENTITY()); 
        break;
    case 'u':
        *_cuboids[0] *= Transform3d(Vector3d(0.0, 0.0, translation_step), Quaternion::IDENTITY()); 
        break;
    case 'j':
        *_cuboids[0] *= Transform3d(Vector3d(0.0, 0.0, -translation_step), Quaternion::IDENTITY()); 
        break;
    
    default:
        std::cout << "  Rotate the box with q/a/w/s/e/d" << std::endl;
        std::cout << "  Translate the box with t/g/y/h/u/j" << std::endl;
        GlutSimulation::normalKey(key, x, y);
        break;
    }
    glutPostRedisplay();

}