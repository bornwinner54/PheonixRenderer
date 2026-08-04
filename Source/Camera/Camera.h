#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
    public :

        Camera();
        ~Camera();

        glm::mat4 GetViewMatrix() const;

        glm::mat4 GetProjectionMatrix() const;

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

};