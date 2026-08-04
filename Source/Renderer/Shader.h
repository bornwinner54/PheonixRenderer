#pragma once
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
    public:
        Shader();
        ~Shader();

    bool Load(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    void Bind() const;
    void Unbind() const;

    void Destroy();

    GLuint GetProgram() const;

    void SetFloat(const std::string& name, float value);

    void SetInt(const std::string& name, int value);

    void SetVec3(const std::string& name,
                 const glm::vec3& value);

    void SetMat4(const std::string& name,
                 const glm::mat4& value);

    private:
        GLuint m_Program = 0;

        std::string ReadFile(const std::string& path);

        GLuint CompileShader(GLenum shaderType,
                            const std::string& source);
};
