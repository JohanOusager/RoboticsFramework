cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(Robotics VERSION 0.0.1)

# gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#gtest end

# Find GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

# Headers
include_directories(
    ${PROJECT_SOURCE_DIR}/robotics
    /robotics
    /external
    /test
)

# Sources
add_subdirectory(robotics/geometry)
add_subdirectory(robotics/math)
add_subdirectory(robotics/simulation)

set(SOURCES
        ${MATH_SOURCES}
        ${GEOMETRY_SOURCES}
        ${SIMULATION_SOURCES}
)

set(SIM_TEST_SRC
    robotics/simulation/GlutSimulationWrapper.cpp
    robotics/simulation/GlutSimulation.cpp
    test/glutSimulation_test.cpp
)

set(BOX_POSE_TEST_SRC 
    test/pose_box_test.cpp
)
set(COLLISION_TEST_SRC 
    test/collision_test.cpp
)

set(GTEST_SRC 
    robotics/math/test/Quaternion_test.cpp
    ${SOURCES}
)

# Make executables
add_executable(sim_test ${SOURCES} ${SIM_TEST_SRC})
add_executable(pose_box_test ${SOURCES} ${BOX_POSE_TEST_SRC})
add_executable(collision_test ${SOURCES} ${COLLISION_TEST_SRC})

enable_testing()
add_executable(gtest_all ${GTEST_SRC} ${SOURCES})

# Link our unit tests against the library we compiled
target_link_libraries(sim_test OpenGL::GL GLUT::GLUT)
target_link_libraries(pose_box_test OpenGL::GL GLUT::GLUT)
target_link_libraries(collision_test OpenGL::GL GLUT::GLUT)

target_link_libraries(gtest_all GTest::gtest_main OpenGL::GL GLUT::GLUT)
include(GoogleTest)
gtest_discover_tests(gtest_all)

# Set the binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)