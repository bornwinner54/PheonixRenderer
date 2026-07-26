#pragma once
#include <cstdint>
#include <GL/glew.h>

class VertexBuffer
{
public:

    VertexBuffer();

    ~VertexBuffer();

    bool Create(const void* data,
                uint32_t size);

    void Bind() const;

    void Unbind() const;

    void Destroy();

    GLuint GetID() const;

private:

    GLuint m_ID;
};