#include "Application.h"
#include "../Platform/Win32/Win32Window.h"
#include "../Renderer/Renderer.h"
#include <iostream>

Application:: Application()
{
    Window = nullptr;
    RendererInstance = nullptr;
    Running = false;
}

Application:: ~Application()
{
    if (RendererInstance) {
        delete RendererInstance;
        RendererInstance = nullptr;
    }

    if (Window) {
        delete Window;
        Window = nullptr;
    }
}

bool Application:: Initialize(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    AllocConsole();

    FILE* fp;

    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    std::cout << "Console initialized\n";

    Window = new Win32Window();
    if(!Window->Initialize(hInstance, 800, 600, L"Renderer_v0.0")) {
        return false;
    }

    RendererInstance = new Renderer(Window);
    if(!RendererInstance->Initialize()) {
        return false;
    }

    Running = true;
    return true;
}

int Application:: Run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    if (!Initialize(hInstance, hPrevInstance, lpszCmdLine, iCmdShow)) {
        std::cout << "Initialization failed. Press Enter to exit...";
        std::cin.get();
        return -1;
    }

    MSG msg;
    while (Running) {

        m_Timer.Tick();

        double dt = m_Timer.GetDeltaTime();
        double fps = m_Timer.GetFPS();

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                Running = false;
            }
            else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        RendererInstance->Render(
                    static_cast<float>(m_Timer.GetDeltaTime()),
                    static_cast<float>(m_Timer.GetTotalTime()));
    }

    return (int)msg.wParam;
}