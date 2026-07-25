#pragma once
#include <windows.h>

class Win32Window
{
    public:
        bool Initialize(HINSTANCE hInstance, int width, int height, const wchar_t* title);
        HWND GetHWND() {return hwnd; };
        HDC GetHDC() {return hdc; };

        static void ToggleFullscreen(HWND hwnd);

        bool IsFullscreen() const;

        int winHeight;
        int winWidth;

    private:
        static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
        HWND hwnd;
        HDC hdc;

        bool m_Fullscreen = false;

        RECT m_WindowRect{};
};