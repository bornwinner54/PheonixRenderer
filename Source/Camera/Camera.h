#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

class Camera
{
    public :

        Camera();
        ~Camera();

        glm::mat4 GetViewMatrix() const;

        glm::mat4 GetProjectionMatrix() const;

        void Move(const glm::vec3& offset);

        const glm::vec3& GetPosition() const;
        const glm::vec3& GetFront() const;
        const glm::vec3& GetRight() const;
        float GetYaw() const;
        float GetPitch() const;

        void SetRotation(float yaw, float pitch);

        void SetAspectRatio(float aspectRatio);

    private:
        glm::vec3 m_Position;
        glm::vec3 m_Front;
        glm::vec3 m_Up;
        glm::vec3 m_Right;

        glm::vec3 m_WorldUp;

        float m_FOV;   
        float m_AspectRatio;
        float m_NearPlane;  
        float m_FarPlane;
        float m_Yaw;
        float m_Pitch;

        

};