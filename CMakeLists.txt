cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)

project(Robotics VERSION 0.01)

# Headers
include_directories(
    ${PROJECT_SOURCE_DIR}/external
    ${PROJECT_SOURCE_DIR}/include
    /include
    /external
    /test
)

# Sources
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES_EXTERNAL external/*.cpp)

set(POSE_BASICS_TEST 
    test/glutSimulation_test.cpp
)
set(GARBAGE_TEST_SRC 
    test/glut_wth_test.cpp
)
#set(SOURCES 
#    src/math/AxisAngle.cpp
#    src/math/Vector3d.cpp
#    src/math/Quaternion.cpp
#    src/math/Pose.cpp
#    src/geometry/Cuboid.cpp
#
#    src/simulation/glutSimulation.cpp
#    test/glutSimulation_test.cpp
#
#    external/GLUT-Object-Oriented-Framework/src/GlutFramework.cpp
#)

# Find packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )


# Make executables
add_executable(pose_basics_test ${SOURCES} ${SOURCES_EXTERNAL} ${POSE_BASICS_TEST})
add_executable(garbage_test ${SOURCES} ${SOURCES_EXTERNAL} ${GARBAGE_TEST_SRC})

# Link our unit tests against the library we compiled
target_link_libraries(pose_basics_test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(garbage_test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# Set the binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)