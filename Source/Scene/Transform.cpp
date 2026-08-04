#include "Transform.h"

Transform::Transform()
    : m_Position(0.0f, 0.0f, 0.0f),
      m_Rotation(0.0f, 0.0f, 0.0f),
      m_Scale(1.0f, 1.0f, 1.0f)
{
}

Transform::~Transform()
{
}

void Transform::SetPosition(const glm::vec3& position)
{
    m_Position = position;
}

void Transform::SetPosition(float x, float y, float z)
{
    m_Position = glm::vec3(x, y, z);
}

void Transform::SetRotation(const glm::vec3& rotation)
{
    m_Rotation = rotation;
}

void Transform::SetRotation(float pitch, float yaw, float roll)
{
    m_Rotation = glm::vec3(pitch, yaw, roll);
}

void Transform::SetScale(const glm::vec3& scale)
{
    m_Scale = scale;
}

void Transform::SetScale(float x, float y, float z)
{
    m_Scale = glm::vec3(x, y, z);
}

void Transform::SetScale(float uniformScale)
{
    m_Scale = glm::vec3(uniformScale);
}

void Transform::Translate(const glm::vec3& offset)
{
    m_Position += offset;
}

void Transform::Rotate(const glm::vec3& offset)
{
    m_Rotation += offset;
}

void Transform::Scale(const glm::vec3& factor)
{
    m_Scale *= factor;
}

const glm::vec3& Transform::GetPosition() const
{
    return m_Position;
}

const glm::vec3& Transform::GetRotation() const
{
    return m_Rotation;
}

const glm::vec3& Transform::GetScale() const
{
    return m_Scale;
}

glm::mat4 Transform::GetModelMatrix() const
{
    glm::mat4 model = glm::mat4(1.0f);
    
    model = glm::translate(
        model,
        m_Position
    );

    model = glm::rotate(
        model,
        glm::radians(m_Rotation.x),
        glm::vec3(1.0f, 0.0f, 0.0f)
    );
    model = glm::rotate(
        model,
        glm::radians(m_Rotation.y),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
    model = glm::rotate(
        model,
        glm::radians(m_Rotation.z),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );


    model = glm::scale(
        model,
        m_Scale
    );

    
    return model;
}