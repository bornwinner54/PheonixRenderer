#pragma once
#include <GL/glew.h>

class VertexArray
{
public:

    VertexArray();

    ~VertexArray();

    bool Create();

    void Bind() const;

    void Unbind() const;

    void Destroy();

    GLuint GetID() const;   

private:

    GLuint m_ID;
};