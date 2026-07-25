#include "Renderer.h"
#include "../Platform/OpenGLContext/GLContext.h"
#include "../Platform/Win32/Win32Window.h"
#include <cmath>

Renderer:: Renderer(Win32Window* window)
{
    Window = window;
    GLContextInstance = new GLContext();
}

bool Renderer::Initialize()
{
    if (!GLContextInstance->Initialize(Window->GetHDC())) {
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

    glClearColor( 0.5f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // Swap the front and back buffers
    GLContextInstance->SwapBuffers(Window->GetHDC());
}

void Renderer::update()
{
    // Update any necessary data for rendering
    
}

void Renderer::Uninitialize()
{
    // Clean up resources if necessary
}