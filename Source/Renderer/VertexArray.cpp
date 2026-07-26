#include "VertexArray.h"
#include <iostream>

VertexArray::VertexArray()
    : m_ID(0)
{
}

VertexArray::~VertexArray()
{
    Destroy();
}

bool VertexArray::Create()
{
    // if array exists, destroy it first
    if (m_ID != 0)
    {
        Destroy();
    }

    glGenVertexArrays(1, &m_ID);

    if(m_ID == 0)
    {
        std::cout << "Failed to generate vertex array." << std::endl;
        return false;
    }

    return true;
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_ID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::Destroy()
{
    if (m_ID != 0)
    {
        glDeleteVertexArrays(1, &m_ID);
        m_ID = 0;
    }
}

GLuint VertexArray::GetID() const
{
    return m_ID;
}