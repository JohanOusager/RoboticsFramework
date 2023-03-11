#include "geometry/Vertex3d.hpp"

using namespace geometry;
using namespace math;

Vertex3d::Vertex3d()
{
    _position = Vector3d::ZERO();
}

Vertex3d::Vertex3d(const Vector3d& position)
{
    _position = position;
}

Vertex3d::Vertex3d(const Vector3d& position, const std::vector<std::shared_ptr<const Vector3d>>& adjacent_vertices)
{
    _position = position;
    _adjacencies = adjacent_vertices;
}

//Vertex3d::Vertex3d(const Vector3d& position, const std::initializer_list<std::shared_ptr<const Vector3d>>& adjacent_vertices)
//{
//    _position = position;
//    _adjacencies = adjacent_vertices;
//}

std::vector<std::shared_ptr<const Vector3d>> Vertex3d::getAdjacencies() const
{
    return _adjacencies;
}

Vector3d Vertex3d::getPosition() const
{
    return _position;
}

void Vertex3d::setPosition(const Vector3d& position)
{
    _position = position;
}

void Vertex3d::removeAdjacency(const std::shared_ptr<const Vector3d>& vertex)
{
    for (uint i = 0; i < _adjacencies.size(); i++)
    {
        if (_adjacencies[i] == vertex)
        {
            _adjacencies.erase(_adjacencies.begin()+i);
            return;
        }
    }
}

void Vertex3d::addAdjacency(const std::shared_ptr<const Vector3d>& vertex)
{
    _adjacencies.push_back(vertex);
}