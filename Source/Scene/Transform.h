#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
    public:
        Transform();
        ~Transform();

        void SetPosition(const glm::vec3& position);
        void SetPosition(float x, float y, float z);

        void SetRotation(const glm::vec3& rotation);
        void SetRotation(float pitch, float yaw, float roll);

        void SetScale(const glm::vec3& scale);
        void SetScale(float x, float y, float z);
        void SetScale(float uniformScale);

        void Translate(const glm::vec3& offset);
        void Rotate(const glm::vec3& offset);
        void Scale(const glm::vec3& factor);

        const glm::vec3& GetPosition() const;
        const glm::vec3& GetRotation() const;
        const glm::vec3& GetScale() const;

        glm::mat4 GetModelMatrix() const;

    private:
        glm::vec3 m_Position;
        glm::vec3 m_Rotation;
        glm::vec3 m_Scale;
};