#pragma once 

#include "math/Vector3d.hpp"

#include "geometry/Vertex3d.hpp"
#include "geometry/Sphere.hpp"
#include "geometry/Cuboid.hpp"

namespace geometry
{

Sphere boundingSphere(const math::Vector3d &centroid, const Vertex3d *verticies_begin, const Vertex3d *vertices_end);

Sphere boundingSphere(const math::Vector3d &centroid, const std::initializer_list<const Vertex3d> &verticies);

Sphere boundingSphere(const math::Vector3d &centroid, const std::vector<const Vertex3d> &verticies);

math::Vector3d centroid(const Vertex3d *verticies_begin, const Vertex3d *vertices_end);

Cuboid boundingCube(const Sphere &sphere);

}