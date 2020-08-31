#include "Main.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND MainWindow;
_3DRadSpaceDll::Game *Game;

#define MENUF_NEWPROJ 1
#define MENUF_OPENPROJ 2
#define MENUF_SAVEPROJ 3
#define MENUF_SAVEPROJAS 4
#define MENUF_PLAY 5
#define MENUF_COMPILE 6
#define MENUF_EXIT 7

#define MENUE_ADDOBJ 8
#define MENUE_ADDADD 9
#define MENUE_IMPORTRES 10
#define MENUE_RESETCURSOR 11

#define MENUO_SETTINGS 12
#define MENUO_CHECKFORUPDATE 13

#define MENUH_ABOUT 14
#define MENUH_DOCS 15
#define MENUH_WEBSITE 16
#define MENUH_FORUM 17
#define MENUH_REPORTBUG 18

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
	LPCWSTR className = L"3DRSP_MAIN";
	WNDCLASS WindowClass = { 0 };
	WindowClass.lpszClassName = className;
	WindowClass.hInstance = hInstance;
	WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hIcon = static_cast<HICON>(LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1)));

    HMENU MMenu = CreateMenu();
    HMENU MenuFile = CreateMenu();
    HMENU MenuEdit = CreateMenu();
    HMENU MenuOptions = CreateMenu();
    HMENU MenuHelp = CreateMenu();

    //File -> ...

    AppendMenu(MenuFile, MF_STRING, MENUF_NEWPROJ, L"New Project");
    AppendMenu(MenuFile, MF_STRING, MENUF_OPENPROJ, L"Open Project");
    AppendMenu(MenuFile, MF_STRING, MENUF_SAVEPROJ, L"Save Project");
    AppendMenu(MenuFile, MF_STRING, MENUF_SAVEPROJAS, L"Save Project As");
    AppendMenu(MenuFile, MF_STRING, MENUF_PLAY, L"Play Project");
    AppendMenu(MenuFile, MF_STRING, MENUF_COMPILE, L"Compile Project");
    AppendMenu(MenuFile, MF_STRING, MENUF_EXIT, L"Exit");

    AppendMenu(MMenu, MF_POPUP, (UINT_PTR)MenuFile, L"File");

    // Edit -> ...

    AppendMenu(MenuEdit, MF_STRING, MENUE_ADDOBJ, L"Add Object");
    AppendMenu(MenuEdit, MF_STRING, MENUE_ADDADD, L"Add addon");
    AppendMenu(MenuEdit, MF_STRING, MENUE_IMPORTRES, L"Import resources");
    AppendMenu(MenuEdit, MF_STRING, MENUE_RESETCURSOR, L"Reset 3D cursor");
    AppendMenu(MMenu, MF_POPUP, (UINT_PTR)MenuEdit, L"Edit");

    AppendMenu(MenuOptions, MF_STRING, MENUO_SETTINGS, L"Options");
    AppendMenu(MenuOptions, MF_STRING, MENUO_CHECKFORUPDATE, L"Check for updates");
    AppendMenu(MMenu, MF_POPUP, (UINT_PTR)MenuOptions, L"Settings");
    
    AppendMenu(MenuHelp, MF_STRING, MENUH_ABOUT, L"About...");
    AppendMenu(MenuHelp, MF_STRING, MENUH_DOCS, L"Documentation");
    AppendMenu(MenuHelp, MF_STRING, MENUH_WEBSITE, L"Website");
    AppendMenu(MenuHelp, MF_STRING, MENUH_FORUM, L"Forum");
    AppendMenu(MenuHelp, MF_STRING, MENUH_REPORTBUG, L"Report a bug...");
    AppendMenu(MMenu, MF_POPUP, (UINT_PTR)MenuHelp, L"Help");
    
    RegisterClass(&WindowClass);

    MainWindow = CreateWindowW(className, L"3DRadSpace", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, MMenu, hInstance, nullptr);

    if (MainWindow == nullptr)
    {
        MessageBox(nullptr, L"Failed to open the window!", L"Fatal error!", MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowWindow(MainWindow, 3);
    
    Game = new _3DRadSpaceDll::Game(MainWindow);
    
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
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW ));

        EndPaint(hwnd, &ps);
        break;
    }
    case WM_KEYUP:
        //trigger onkeyup
        break;
    case WM_KILLFOCUS:
        //clear input.keyboard
        break;
    case WM_KEYDOWN:
    {
        //trigger onkeydown
        if (!(lParam & 0x40000000)) //prevent autorepeating
        {

        }
        break;
    }
    case WM_CHAR:
        //text imput
        break;
    case WM_MOUSEMOVE: //handle mouse movment
    {
        POINTS point = MAKEPOINTS(lParam);
        RECT wr = { 0 };
        GetWindowRect(MainWindow, &wr);
        if (point.x > 0 && point.y > 0)
        {

        }
        break;
    }
    case WM_LBUTTONUP: //mouse left button up
    {
        POINTS point = MAKEPOINTS(lParam);
        break;
    }
    case WM_LBUTTONDOWN: //mouse left button down
    {
        POINTS point = MAKEPOINTS(lParam);
        break;
    }
    case WM_RBUTTONUP: //mouse right button up
    {
        POINTS point = MAKEPOINTS(lParam);
        break;
    }
    case WM_RBUTTONDOWN: //mouse right button down
    {
        POINTS point = MAKEPOINTS(lParam);
        break;
    }
    case WM_MOUSEWHEEL:
    {
        POINTS pt = MAKEPOINTS(lParam);
        auto dw = GET_WHEEL_DELTA_WPARAM(wParam);
        if (dw > 0)
        {

        }
        else if (dw < 0)
        {

        }
    }
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        //File -> ...
        case MENUF_NEWPROJ:
            break;
        case MENUF_OPENPROJ:
            break;
        case MENUF_SAVEPROJ:
            break;
        case MENUF_SAVEPROJAS:
            break;
        case MENUF_PLAY:
            break;
        case MENUF_COMPILE:
            break;
        case MENUF_EXIT:
            exit(0);
        //Edit -> ...
            
        default: break;
        }
    }
    return 0;

    }
    
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}