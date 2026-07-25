#pragma once
#include <windows.h>
#include "Core/Timer.h"

class Win32Window;
class Renderer;

class Application {
    public:
        Application();
        ~Application();

        int Run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow);

    private:
        bool Initialize(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow);

        Win32Window* Window;
        Renderer* RendererInstance;

        Timer m_Timer;

        bool Running;
};