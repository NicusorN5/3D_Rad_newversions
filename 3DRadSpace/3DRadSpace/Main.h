#pragma once
#include <windows.h>
#include <CommCtrl.h>
#include "3DRadSpaceDll_h/Game.h"
#include "3DRadSpaceDll_h/Camera.h"
#include "3DRadSpaceDll_h/Math.h"
#include "resource.h"
#include <vector>
#include <tchar.h>

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

#define TOOLB_SW2D 19

//Enable visual styles
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "comctl32.lib")

extern HWND MainWindow;
extern HWND DrawWindow;
extern _3DRadSpaceDll::Game *Game;

extern std::vector<_3DRadSpaceDll::GameObject*> Objects;

extern _3DRadSpaceDll::Camera *Camera;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd);

void ResizeWindow();
BOOL DirectoryExists(LPCTSTR szPath);
void CreateDirectoryIfExists(LPCWSTR path);

void SaveProject();
void SaveProjectAs();
void SaveProjectFile(wchar_t* file);
void CreateProjectsFolder();

constexpr const wchar_t* OPN_FILTER_PROJECT = L"3DRadSpace Project (*.3drsp)\0*.3drsp\0Text files(*.txt)\0*.txt";