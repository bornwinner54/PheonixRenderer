#include "Mesh.h"

Mesh::Mesh()
    : m_VertexCount(0)
{
}

Mesh::~Mesh()
{
    Destroy();
}

bool Mesh :: Create(const std::vector<Vertex>& vertices)
{
    Destroy();

    m_VertexCount = static_cast<uint32_t>(vertices.size());

    if(m_VertexCount == 0)
    {
        return false;
    }

    if(!m_VertexArray.Create())
    {
        return false;
    }

    if(!m_VertexBuffer.Create(vertices.data(), m_VertexCount * sizeof(Vertex)))
    {
        return false;
    }

    m_VertexArray.Bind();
    m_VertexBuffer.Bind();

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    m_VertexBuffer.Unbind();
    m_VertexArray.Unbind();

    return true;
}

void Mesh :: Draw() const
{
    m_VertexArray.Bind();

    glDrawArrays(GL_TRIANGLES, 0, m_VertexCount);
    
    m_VertexArray.Unbind();
}

void Mesh :: Destroy()
{
    m_VertexBuffer.Destroy();
    m_VertexArray.Destroy();

    m_VertexCount = 0;
}