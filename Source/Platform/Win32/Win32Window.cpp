#include "Win32Window.h"
#include "Resources/Resources.h"

bool Win32Window::Initialize(HINSTANCE hInstance, int width, int height, const wchar_t* title) {
    WNDCLASSEXW wndclass{};

    wndclass.cbSize = sizeof(WNDCLASSEXW);
    wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wndclass.cbClsExtra = 0;    
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = Win32Window :: WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = title;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    RegisterClassExW(&wndclass);

    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);

    int winInitialX = (screenWidth / 2) - (width / 2);
    int winInitialY = (screenHeight / 2) - (height / 2);

    hwnd = CreateWindowExW(WS_EX_APPWINDOW,
        title,
        title,
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
        winInitialX,
        winInitialY,
        width,
        height,
        NULL,
        NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, SW_SHOW);
    SetForegroundWindow(hwnd);  

    hdc = GetDC(hwnd);

    return true;
}

LRESULT CALLBACK Win32Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    //     case WM_SETFOCUS:
	// 	gbActive = TRUE;
	// 	break;

	// case WM_KILLFOCUS:
	// 	gbActive = FALSE;
	// 	break;

	// case WM_SIZE:
	// 	resize_cube(LOWORD(lParam),HIWORD(lParam));
	// 	break;

	case WM_ERASEBKGND:
		return(0);

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
        
        case VK_F11:
            
            ToggleFullscreen(hwnd);
            break;

		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		default:
			break;
		}
		break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
            break;
        }
        break;
	

	case WM_RBUTTONDOWN:
		DestroyWindow(hwnd);
		break;
		
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

void Win32Window::ToggleFullscreen(HWND hwnd)
{
    static bool fullscreen = false;
    static RECT previousRect{};

    fullscreen = !fullscreen;

    if (fullscreen)
    {
        // Save current window position/size
        GetWindowRect(hwnd, &previousRect);

        // Remove window border/title bar
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);

        // Get monitor size
        MONITORINFO monitorInfo{};
        monitorInfo.cbSize = sizeof(MONITORINFO);

        GetMonitorInfo(
            MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY),
            &monitorInfo);

        // Resize window to monitor
        SetWindowPos(
            hwnd,
            HWND_TOP,
            monitorInfo.rcMonitor.left,
            monitorInfo.rcMonitor.top,
            monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left,
            monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top,
            SWP_FRAMECHANGED);
    }
    else
    {
        // Restore normal window style
        SetWindowLongPtr(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);

        // Restore previous size/position
        SetWindowPos(
            hwnd,
            HWND_TOP,
            previousRect.left,
            previousRect.top,
            previousRect.right - previousRect.left,
            previousRect.bottom - previousRect.top,
            SWP_FRAMECHANGED);
    }
}