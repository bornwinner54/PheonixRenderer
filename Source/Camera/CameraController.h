#pragma once 

#include "Camera.h"

class CameraController
{
    public:
        CameraController(Camera& camera);
        ~CameraController();

        void update(float deltaTime);
    
    private:
        Camera& m_Camera;

        float m_MovementSpeed;
        float m_MouseSensitivity;

        float m_LastMouseX;
        float m_LastMouseY;

        bool m_FirstMouse;
        
};