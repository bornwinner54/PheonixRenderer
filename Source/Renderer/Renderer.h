#pragma once

class Win32Window;
class GLContext;
#include <GL/glew.h>
#include <GL/gl.h>
#include "Shader.h"
#include "Mesh.h"
#include "../Scene/Transform.h"

class Renderer {
    public:
        Renderer(Win32Window* window);
        bool Initialize();
        void resize(int width, int height);
        void Render(float deltaTime, float totalTime);
        void update();
        void Uninitialize();

    private:
        Win32Window* Window;
        GLContext* GLContextInstance;
        Shader* m_Shader;
        Mesh* m_triangleMesh;
        Transform m_transform;
};