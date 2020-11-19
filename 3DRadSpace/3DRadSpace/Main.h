#pragma once
#define NOMINMAX
#include <windows.h>
#include <CommCtrl.h>
#include "3DRadSpaceDll_h/Game.h"
#include "3DRadSpaceDll_h/Camera.h"
#include "3DRadSpaceDll_h/Math.h"
#include "3DRadSpaceDll_h/Texture2D.h"
#include "resource.h"
#include <vector>
#include <tchar.h>
#include "3DRadSpaceDll_h/Model3D.h"
#pragma comment(lib,"D3DCompiler.lib")
#include <d3dcompiler.h>

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

#define MENUC_EDITOBJ 20
#define MENUC_DELETEOBJ 21

//Enable visual styles
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "comctl32.lib")

extern HWND MainWindow;
extern HWND DrawWindow;
extern _3DRadSpaceDll::Game *Game;

extern std::vector<_3DRadSpaceDll::IGameObject*> Objects;

extern _3DRadSpaceDll::Camera *Camera;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd);

LRESULT CALLBACK DrawWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void ResizeWindow();
BOOL DirectoryExists(LPCTSTR szPath);
void CreateDirectoryIfExists(LPCWSTR path);

void SaveProject();
void SaveProjectAs();
void SaveProjectFile(wchar_t* file);
void CreateProjectsFolder();

constexpr const wchar_t* OPN_FILTER_PROJECT = L"3DRadSpace Project (*.3drsp)\0*.3drsp\0Text files(*.txt)\0*.txt";
constexpr const wchar_t* OPN_FILTER_RESOURCE = L"DirectX Mesh(*.x)\0*.x\0Image files(*.png,*.bmp,*.jpeg)\0*.png;*.bmp;*.jpeg";

void AddItem(wchar_t* Item);

extern _3DRadSpaceDll::Matrix MView;
extern _3DRadSpaceDll::Matrix MProjetion;

struct CameraBuffer
{
	DirectX::XMMATRIX World, View, Projection;
};