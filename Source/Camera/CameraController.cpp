#include "CameraController.h"

#include <Windows.h>

CameraController::CameraController(Camera& camera)
    : m_Camera(camera), m_MovementSpeed(5.0f), m_MouseSensitivity(0.1f), m_LastMouseX(0.0f),
      m_LastMouseY(0.0f),
      m_FirstMouse(true)
{
}

CameraController::~CameraController()
{
}

void CameraController::update(float deltaTime)
{
    float movement = m_MovementSpeed * deltaTime;

    if(GetAsyncKeyState('W') & 0x8000)
    {
        m_Camera.Move(m_Camera.GetFront() * movement);
    }

    if(GetAsyncKeyState('S') & 0x8000)
    {
        m_Camera.Move(-m_Camera.GetFront() * movement);
    }

    if(GetAsyncKeyState('A') & 0x8000)
    {
        m_Camera.Move(-m_Camera.GetRight() * movement);
    }

    if(GetAsyncKeyState('D') & 0x8000)
    {
        m_Camera.Move(m_Camera.GetRight() * movement);
    }

    POINT mousePosition;

    if (GetCursorPos(&mousePosition))
    {
        float mouseX = static_cast<float>(mousePosition.x);
        float mouseY = static_cast<float>(mousePosition.y);

        if (m_FirstMouse)
        {
            m_LastMouseX = mouseX;
            m_LastMouseY = mouseY;
            m_FirstMouse = false;
        }

        float mouseOffsetX = mouseX - m_LastMouseX;
        float mouseOffsetY = m_LastMouseY - mouseY;

        m_LastMouseX = mouseX;
        m_LastMouseY = mouseY;

        mouseOffsetX *= m_MouseSensitivity;
        mouseOffsetY *= m_MouseSensitivity;

        float pitch = m_Camera.GetPitch() + mouseOffsetY;

        pitch = glm::clamp(pitch, -89.0f, 89.0f);

        float yaw = m_Camera.GetYaw() + mouseOffsetX;

        m_Camera.SetRotation(yaw, pitch);
    }
}