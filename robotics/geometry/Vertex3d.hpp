#pragma once

#include <vector>
#include <memory>

#include "math/Vector3d.hpp"

namespace geometry
{

    class Vertex3d
    {

    public:
        Vertex3d();

        Vertex3d(const math::Vector3d &position);

        Vertex3d(const math::Vector3d &position, const std::vector<std::shared_ptr<const math::Vector3d>> &adjacent_vertices);

        // Vertex3d::Vertex3d(const Vector3d& position, const std::initializer_list<std::shared_ptr<const Vector3d>>& adjacent_vertices);

        std::vector<std::shared_ptr<const math::Vector3d>> getAdjacencies() const;

        math::Vector3d getPosition() const;

        void setPosition(const math::Vector3d &position);

        void removeAdjacency(const std::shared_ptr<const math::Vector3d> &vertex);

        void addAdjacency(const std::shared_ptr<const math::Vector3d> &vertex);

    private:
        std::vector<std::shared_ptr<const math::Vector3d>> _adjacencies; // Should definitely be vertices
        math::Vector3d _position;
    };

}