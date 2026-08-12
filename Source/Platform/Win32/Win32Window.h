#pragma once
#include <windows.h>
#include <functional>

class Win32Window
{
    public:
        using ResizeCallback = std::function<void(int, int)>;
        bool Initialize(HINSTANCE hInstance, int width, int height, const wchar_t* title);
        HWND GetHWND() {return hwnd; };
        HDC GetHDC() {return hdc; };

        static void ToggleFullscreen(HWND hwnd);
        void SetResizeCallback(ResizeCallback callback);
        bool IsFullscreen() const;

        int winHeight;
        int winWidth;
        

    private:
        static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
        void HandleResize(int width, int height);
        HWND hwnd;
        HDC hdc;

        bool m_Fullscreen = false;

        RECT m_WindowRect{};
        ResizeCallback m_ResizeCallback;
};