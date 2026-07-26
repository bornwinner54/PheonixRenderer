#pragma once

#include <vector>

#include "Vertex.h"
#include "VertexBuffer.h"
#include "VertexArray.h"

class Mesh
{
    public:
        Mesh();
        ~Mesh();

        bool Create(const std::vector<Vertex>& vertices);
        void Draw() const;
        void Destroy();

    private:
        VertexArray m_VertexArray;
        VertexBuffer m_VertexBuffer;
        uint32_t m_VertexCount;
};