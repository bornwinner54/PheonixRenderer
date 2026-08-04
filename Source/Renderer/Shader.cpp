#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader()
    : m_Program(0)
{
}

Shader::~Shader()
{
    Destroy();
}

void Shader::SetMat4(const std::string& name, const glm::mat4& value)
{
    GLint location = glGetUniformLocation(m_Program, name.c_str());
    
    if(location == -1)
    {
        std::cerr << "Uniform '" << name << "' not found in shader program." << std::endl;
        return;
    }

    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetFloat(
    const std::string& name,
    float value)
{
    GLint location =
        glGetUniformLocation(
            m_Program,
            name.c_str()
        );

    if (location == -1)
    {
        std::cerr
            << "Uniform not found: "
            << name
            << std::endl;
        return;
    }

    glUniform1f(location, value);
}

void Shader::SetInt(
    const std::string& name,
    int value)
{
    GLint location =
        glGetUniformLocation(
            m_Program,
            name.c_str()
        );

    if (location == -1)
    {
        std::cerr
            << "Uniform not found: "
            << name
            << std::endl;
        return;
    }

    glUniform1i(location, value);
}

void Shader::SetVec3(
    const std::string& name,
    const glm::vec3& value)
{
    GLint location =
        glGetUniformLocation(
            m_Program,
            name.c_str()
        );

    if (location == -1)
    {
        std::cerr
            << "Uniform not found: "
            << name
            << std::endl;
        return;
    }

    glUniform3fv(
        location,
        1,
        glm::value_ptr(value)
    );
}

GLuint Shader::CompileShader(GLenum shaderType,
                             const std::string& source)
{
    std::cout << "Compiling shaders..." << std::endl;
    GLuint shader = glCreateShader(shaderType);

    const char* shaderSource = source.c_str();

    glShaderSource(shader,
                   1,
                   &shaderSource,
                   nullptr);

    glCompileShader(shader);

    GLint success = GL_FALSE;

    glGetShaderiv(shader,
                  GL_COMPILE_STATUS,
                  &success);

    if (!success)
    {
        GLint logLength = 0;

        glGetShaderiv(shader,
                      GL_INFO_LOG_LENGTH,
                      &logLength);

        std::string errorLog(logLength, '\0');

        glGetShaderInfoLog(shader,
                           logLength,
                           nullptr,
                           errorLog.data());

        std::cerr << "=========================================\n";

        if (shaderType == GL_VERTEX_SHADER)
            std::cerr << "Vertex Shader Compilation Failed\n";
        else if (shaderType == GL_FRAGMENT_SHADER)
            std::cerr << "Fragment Shader Compilation Failed\n";

        std::cerr << errorLog << std::endl;

        std::cerr << "=========================================\n";

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}

bool Shader::Load(const std::string& vertexShaderPath,
                  const std::string& fragmentShaderPath)
{
    std::cout << "Loading shaders..." << std::endl;
    Destroy();
    std::string vertexSource = ReadFile(vertexShaderPath);
    std::string fragmentSource = ReadFile(fragmentShaderPath);
    if (vertexSource.empty() || fragmentSource.empty())
    {
        std::cout << "shader files are empty" << std::endl;
        return false;
    }

    GLuint vertexShader =
        CompileShader(GL_VERTEX_SHADER, vertexSource);
    if (vertexShader == 0)
    {
        std::cout << "Vertex shader compilation failed." << std::endl;
        return false;
    }
    std::cout << "Vertex shader compiled successfully.\n";

    GLuint fragmentShader =
        CompileShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (fragmentShader == 0)
    {
        std::cout << "Fragment shader compilation failed." << std::endl;
        return false;
    }
    std::cout << "Fragment shader compiled successfully.\n";

    GLuint program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    GLint success = GL_FALSE;

    glGetProgramiv(
        program,
        GL_LINK_STATUS,
        &success
    );

    if (success == GL_FALSE)
    {
        GLint logLength = 0;

        glGetProgramiv(
            program,
            GL_INFO_LOG_LENGTH,
            &logLength
        );

        std::string errorLog(logLength, '\0');

        glGetProgramInfoLog(
            program,
            logLength,
            nullptr,
            errorLog.data()
        );

        std::cerr << "=========================================\n";
        std::cerr << "Shader Program Link Failed\n";
        std::cerr << errorLog << std::endl;
        std::cerr << "=========================================\n";

        glDeleteProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return false;
    }
    std::cout << "Shader program linked successfully.\n";

    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    m_Program = program;
    std::cout << "Shader loaded successfully.\n";

    return true;
}

std::string Shader::ReadFile(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "=========================================\n";
        std::cerr << "Failed to open shader file\n";
        std::cerr << path << "\n";
        std::cerr << "=========================================\n";

        return "";
    }

    std::stringstream stream;
    stream << file.rdbuf();

    file.close();

    return stream.str();
}

void Shader::Bind() const
{
    glUseProgram(m_Program);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

GLuint Shader::GetProgram() const
{
    return m_Program;
}

void Shader::Destroy()
{
    if (m_Program != 0)
    {
        glDeleteProgram(m_Program);
        m_Program = 0;
    }
}