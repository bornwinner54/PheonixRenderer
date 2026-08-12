#include "Camera.h"

Camera::Camera()
    : m_Position(glm::vec3(0.0f, 0.0f, 3.0f)),
      m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
      m_Up(glm::vec3(0.0f, 1.0f, 0.0f)),
      m_Right(glm::normalize(glm::cross(m_Front, m_Up))),
      m_WorldUp(m_Up),
      m_Yaw(-90.0f),
      m_Pitch(0.0f),
      m_FOV(45.0f),
      m_AspectRatio(4.0f / 3.0f),
      m_NearPlane(0.1f),
      m_FarPlane(100.0f)
{
    SetRotation(m_Yaw, m_Pitch);
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

float Camera::GetYaw() const
{
    return m_Yaw;
}

float Camera::GetPitch() const
{
    return m_Pitch;
}

void Camera::Move(const glm::vec3& offset)
{
    m_Position += offset;
}

const glm::vec3& Camera::GetPosition() const
{
    return m_Position;
}

const glm::vec3& Camera::GetFront() const
{
    return m_Front;
}

const glm::vec3& Camera::GetRight() const
{
    return m_Right;
}

void Camera::SetAspectRatio(float aspectRatio)
{
    m_AspectRatio = aspectRatio;
}

void Camera::SetRotation(float yaw, float pitch)
{
    m_Yaw = yaw;
    m_Pitch = pitch;

    glm::vec3 front;

    front.x = cos(glm::radians(m_Yaw)) *
              cos(glm::radians(m_Pitch));

    front.y = sin(glm::radians(m_Pitch));

    front.z = sin(glm::radians(m_Yaw)) *
              cos(glm::radians(m_Pitch));

    m_Front = glm::normalize(front);

    m_Right = glm::normalize(
        glm::cross(m_Front, m_WorldUp)
    );

    m_Up = glm::normalize(
        glm::cross(m_Right, m_Front)
    );
}