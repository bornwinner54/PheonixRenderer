#pragma once
#include <windows.h>

class GLContext {
    public:
        bool Initialize(HDC hdc);
        void SwapBuffers(HDC hdc);
        void Resize(HDC hdc, int width, int height);

    private:
        HGLRC ghrc;
};