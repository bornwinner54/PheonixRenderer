#include "GLContext.h"
#include <gl/glew.h>
#include <gl/GL.h>

bool GLContext::Initialize(HDC hdc) {

    PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd,sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

    iPixelFormatIndex = ChoosePixelFormat(hdc, &pfd);  //it should be non 0 positive value
    if (iPixelFormatIndex == 0) {
        return false;
    }

    if (SetPixelFormat(hdc, iPixelFormatIndex, &pfd) == FALSE) {
        return false;
    }

    ghrc = wglCreateContext(hdc);
    if (ghrc == NULL) {
        return false;
    }

    if (wglMakeCurrent(hdc, ghrc) == FALSE) {
        return false;
    }

    if(glewInit() != GLEW_OK) {
        return false;
    }

    return true;
}

void GLContext::SwapBuffers(HDC hdc) {
    ::SwapBuffers(hdc);
}

void GLContext::Resize(HDC hdc, int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}