#include "Core/Application.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {
    Application app;
    return app.Run(hInstance, hPrevInstance, lpszCmdLine, iCmdShow);
}