#include "geometry/Convert.hpp"

using namespace geometry;
using namespace math;

Sphere boundingSphere(const Vector3d &centroid, const Vertex3d *verticies_begin, const Vertex3d *vertices_end)
{
    double max_distance = (verticies_begin->getPosition() - centroid).magnitude();
    double distance;
    for (const Vertex3d *it = verticies_begin + 1; it != vertices_end; it++)
    {
        distance = (it->getPosition() - centroid).magnitude();
        if (distance < max_distance)
            max_distance = distance;
    }
    return {centroid, distance};
}

Sphere boundingSphere(const Vector3d &centroid, const std::initializer_list<const Vertex3d> &verticies)
{
    return Sphere(centroid, 0); //boundingSphere(centroid, verticies.begin(), verticies.end());
}

Sphere boundingSphere(const Vector3d &centroid, const std::vector<const Vertex3d> &verticies)
{
    // const Vertex3d* const a = verticies.data();
    // return boundingSphere(centroid, verticies.data(), verticies.data() + verticies.size());
    return Sphere(Vector3d::ZERO(), 0);
}

Vector3d centroid(const Vertex3d *verticies_begin, const Vertex3d *vertices_end)
{
    Vector3d centroid = Vector3d::ZERO();
    uint count = 0;
    for (const Vertex3d *it = verticies_begin; it != vertices_end; it++)
    {
        centroid += it->getPosition();
        count++;
    }
    return centroid / count;
}

Cuboid boundingCube(const Sphere &sphere)
{
    return Cuboid(Transform3d::IDENTITY(), 0, 0, 0);
}
