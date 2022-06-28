#include "simulation/BoxPoseSimulation.hpp"

BoxPoseSimulation::BoxPoseSimulation()
{
    addCuboid(std::make_shared<Cuboid>(std::make_shared<Pose>(Pose::IDENTITY()), 5.0, 10.0, 2.5));
}

void BoxPoseSimulation::normalKey(unsigned char key, int x, int y)
{
    double angle_step = math::toRadians(5.0);
    switch (key)
    {
    case 'q':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(1.0, 0.0, 0.0)))); 
        break;
    case 'a':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(1.0, 0.0, 0.0)))); 
        break;
    case 'w':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(0.0, 1.0, 0.0)))); 
        break;
    case 's':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(0.0, 1.0, 0.0)))); 
        break;
    case 'e':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(angle_step, Vector3d(0.0, 0.0, 1.0)))); 
        break;
    case 'd':
        *_cuboids[0] *= Pose(Vector3d::ZERO(), math::toQuaternion(AxisAngle(-angle_step, Vector3d(0.0, 0.0, 1.0)))); 
        break;
    
    default:
        std::cout << "Rotate the box with q/a/w/s/e/d" << std::endl;
        GlutSimulation::normalKey(key, x, y);
        break;
    }
    glutPostRedisplay();

}