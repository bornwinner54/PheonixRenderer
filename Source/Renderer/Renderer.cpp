#include "Renderer.h"
#include "../Platform/OpenGLContext/GLContext.h"
#include "../Platform/Win32/Win32Window.h"
#include <cmath>

Renderer:: Renderer(Win32Window* window)
{
    Window = window;
    GLContextInstance = new GLContext();
    m_Shader = nullptr;
}

bool Renderer::Initialize()
{
    if (!GLContextInstance->Initialize(Window->GetHDC())) {
        return false;
    }

    m_Shader = new Shader();
    if (!m_Shader->Load(
            "Assets/Shaders/Basic.vert",
            "Assets/Shaders/Basic.frag"))
    {
        return false;
    }

    std::vector<Vertex> vertices = {
        {{  0.0f,  0.5f, 0.0f }},
        {{ -0.5f, -0.5f, 0.0f }},
        {{  0.5f, -0.5f, 0.0f }}
    };

    m_triangleMesh = new Mesh();

    m_transform.SetPosition(0.0f, 0.0f, 0.0f);
    m_transform.SetRotation(0.0f, 0.0f, 0.0f);
    m_transform.SetScale(1.0f);

    if (!m_triangleMesh->Create(vertices)) {
        return false;
    }

    return true;
}

void Renderer::resize(int width, int height)
{
    // Handle window resizing if necessary
    if (height <= 0) {
		height = 1;
	}

	Window-> winWidth = width;
	Window-> winHeight = height;

    GLContextInstance->Resize(Window->GetHDC(), width, height);
}

void Renderer::Render(float deltaTime, float totalTime)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // Swap the front and back buffers

    glm::mat4 model = m_transform.GetModelMatrix();
    glm::mat4 view = m_camera.GetViewMatrix();
    glm::mat4 projection = m_camera.GetProjectionMatrix();

    m_Shader->Bind();

    m_Shader->SetMat4(
        "u_Model",
        model
    );

    m_Shader->SetMat4(
        "u_View",
        view
    );

    m_Shader->SetMat4(
        "u_Projection",
        projection
    );

    m_triangleMesh->Draw();
    m_Shader->Unbind();

    GLContextInstance->SwapBuffers(Window->GetHDC());
}

void Renderer::update()
{
    // Update any necessary data for rendering
    
}

void Renderer::Uninitialize()
{
    // Clean up resources if necessary
    delete m_Shader;
    m_Shader = nullptr;
    
    if (m_triangleMesh)
{
    delete m_triangleMesh;
    m_triangleMesh = nullptr;
}
}