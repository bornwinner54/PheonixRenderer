#pragma once
#include <string>
#include <GL/glew.h>

class Shader {
    public:
        Shader();
        ~Shader();

    bool Load(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    void Bind() const;
    void Unbind() const;

    void Destroy();

    GLuint GetProgram() const;

    private:
        GLuint m_Program = 0;

        std::string ReadFile(const std::string& path);

        GLuint CompileShader(GLenum shaderType,
                            const std::string& source);
};
