#include "Camera.h"

Camera::Camera()
    : m_Position(glm::vec3(0.0f, 0.0f, 3.0f)),
      m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
      m_Up(glm::vec3(0.0f, 1.0f, 0.0f)),
      m_Right(glm::normalize(glm::cross(m_Front, m_Up))),
      m_WorldUp(m_Up),
      m_FOV(45.0f),
      m_AspectRatio(4.0f / 3.0f),
      m_NearPlane(0.1f),
      m_FarPlane(100.0f)
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix() const
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane);
}