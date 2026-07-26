#include "VertexBuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer()
    : m_ID(0)
{
}

VertexBuffer::~VertexBuffer()
{
    Destroy();
}

bool VertexBuffer::Create(const void* data, uint32_t size)
{
   // if buffer exists, destroy it first
    if (m_ID != 0)
    {
        Destroy();
    }

    glGenBuffers(1, &m_ID);

    if(m_ID == 0)
    {
        std::cout << "Failed to generate vertex buffer." << std::endl;
        return false;
    }

    glBindBuffer(GL_ARRAY_BUFFER, m_ID);

    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return true;
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Destroy()
{
    if (m_ID != 0)
    {
        glDeleteBuffers(1, &m_ID);
        m_ID = 0;
    }
}

GLuint VertexBuffer::GetID() const
{
    return m_ID;
}