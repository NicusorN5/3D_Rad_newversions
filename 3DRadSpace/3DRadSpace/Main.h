#pragma once
#include <windows.h>
#include <CommCtrl.h>
#include "3DRadSpaceDll_h/Game.h"
#include "resource.h"

//Enable visual styles
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version = '6.0.0.0' processorArchitecture = '*' publicKeyToken = '6595b64144ccf1df' language = '*'\"")
#pragma comment(lib, "comctl32.lib")

extern HWND MainWindow;
extern HWND DrawWindow;
extern _3DRadSpaceDll::Game *Game;