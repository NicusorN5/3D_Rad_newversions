#include "Main.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND MainWindow;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
	LPCWSTR className = L"3DRSP_MAIN";
	WNDCLASS WindowClass = { 0 };
	WindowClass.lpszClassName = className;
	WindowClass.hInstance = hInstance;
	WindowClass.lpfnWndProc = WindowProc;

    RegisterClass(&WindowClass);

    MainWindow = CreateWindowW(className, L"3DRadSpace", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, nullptr);
    
    HMENU Menu = CreateMenu();

    AppendMenuW(Menu, MF_STRING, 1, L"New project");
    AppendMenuW(Menu, MF_STRING, 2, L"Open project");
    AppendMenuW(Menu, MF_STRING, 3, L"Save project");

    if (MainWindow == nullptr)
    {
        MessageBox(nullptr, L"Failed to open the window!", L"Fatal error!", MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowWindow(MainWindow, 3);

    MSG msg = { 0 };



    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 1;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}