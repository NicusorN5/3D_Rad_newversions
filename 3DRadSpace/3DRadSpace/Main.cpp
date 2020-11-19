#include "Main.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND MainWindow;
HWND DrawWindow;
_3DRadSpaceDll::Game *Game;

bool Wopen = true;

HBRUSH window_color_brush = nullptr;
HWND hObjectsList = nullptr;
HWND hToolbar = nullptr;

HINSTANCE hCrtInstance;

std::vector<_3DRadSpaceDll::IGameObject*> Objects;
_3DRadSpaceDll::Camera* Camera;

wchar_t LastFile[255];
bool Saved = true;

_3DRadSpaceDll::Matrix MView;
_3DRadSpaceDll::Matrix MProjetion;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	hCrtInstance = hInstance;

	LPCWSTR className = L"3DRSP_MAIN";
	WNDCLASS WindowClass = { 0 };
	WindowClass.lpszClassName = className;
	WindowClass.hInstance = hInstance;
	WindowClass.lpfnWndProc = WindowProc;
	WindowClass.hIcon = static_cast<HICON>(LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1)));
	RegisterClass(&WindowClass);

	LPCWSTR DrwClassName = L"DRAWWINDOW";
	WNDCLASS DrwWindow = { 0 };
	DrwWindow.lpszClassName = DrwClassName;
	DrwWindow.hInstance = hInstance;
	DrwWindow.lpfnWndProc = DrawWindowProc;
	DrwWindow.hIcon = static_cast<HICON>(LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)));
	RegisterClass(&DrwWindow);

	HMENU MMenu = CreateMenu();
	HMENU MenuFile = CreateMenu();
	HMENU MenuEdit = CreateMenu();
	HMENU MenuOptions = CreateMenu();
	HMENU MenuHelp = CreateMenu();

	HWND hToolbar = nullptr;

	window_color_brush = CreateSolidBrush(RGB(128, 128, 128));

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

	MainWindow = CreateWindowW(className, L"3DRadSpace v0.1.0 alpha", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, MMenu, hInstance, nullptr);
	DrawWindow = CreateWindow(DrwClassName, L"3D View", WS_CHILD  , 150, 55, 800, 600, MainWindow, nullptr, hInstance, nullptr);
	hObjectsList = CreateWindow(WC_LISTVIEW, L"", WS_CHILD | WS_VISIBLE, 0, 0, 150, 600, MainWindow, nullptr, hInstance, nullptr);
	if (MainWindow == nullptr)
	{
		MessageBox(nullptr, L"Failed to open the window!", L"Fatal error!", MB_OK | MB_ICONERROR);
		return 1;
	}
	hToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, nullptr, WS_CHILD | TBSTYLE_LIST, 0, 0, 0, 0, MainWindow, nullptr, hInstance, nullptr);

	if (hToolbar == nullptr)
	{
		MessageBox(nullptr, L"Failed to create the toolbar", L"Error", MB_ICONERROR | MB_OK);
		return 1;
	}

	HIMAGELIST imgToolbarList = ImageList_Create(16, 16, ILC_COLOR32 | ILC_MASK, 6, 2);
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON4)));
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)));
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON3)));
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON5)));
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON6)));
	ImageList_AddIcon(imgToolbarList, LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON7)));

	SendMessage(hToolbar, TB_SETIMAGELIST, (WPARAM)0, (WPARAM)imgToolbarList);

	TBBUTTON tbButtons[6] =
	{
		{ 0,MENUF_NEWPROJ ,  TBSTATE_ENABLED, BTNS_SHOWTEXT | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"New" },
		{ 1, MENUF_OPENPROJ, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Open"},
		{ 2, MENUF_SAVEPROJ, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Save"},
		{ 3, MENUF_PLAY, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Play"},
		{ 4, MENUF_COMPILE, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Compile"},
		{ 5, TOOLB_SW2D, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Switch 2D/3D"}
	};

	SendMessage(hToolbar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
	SendMessage(hToolbar, TB_ADDBUTTONS, (WPARAM)6, (LPARAM)&tbButtons);

	SendMessage(hToolbar, TB_AUTOSIZE, 0, 0);

	ShowWindow(MainWindow, 3);
	ShowWindow(DrawWindow, 1);

	//SendMessage(hToolbar, TB_AUTOSIZE, 0, 0);
	ShowWindow(hToolbar, 3);
	
	ResizeWindow();

	CreateProjectsFolder();

	AddItem((wchar_t*)L"eks dee");

	Game = new _3DRadSpaceDll::Game(DrawWindow);
	Camera = new _3DRadSpaceDll::Camera((char*)"EditorCamera", true, _3DRadSpaceDll::Vector3(0, 1, 1), _3DRadSpaceDll::Vector3(0), _3DRadSpaceDll::Vector3(0, 1, 0), 800.0f / 600.0f, _3DRadSpaceDll::Math::ToRadians(45.0f), 0.01f, 500.0f);

	ID3D11Device* Device = Game->GetDevice();
	IDXGISwapChain* SwapChain = Game->GetSwapChain();
	ID3D11DeviceContext* DeviceContext = Game->GetDeviceContext();

	_3DRadSpaceDll::Texture2D* test_texture = _3DRadSpaceDll::Texture2D::FromFile(L"doge.png", Device, DeviceContext);

	ID3D11RenderTargetView* renderTarget;
	ID3D11Asynchronous* _async = nullptr;
 
	ID3D11Texture2D* BackBuffer = nullptr;
	SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);
	if (BackBuffer == nullptr)
	{
		MessageBox(nullptr, L"Failed to create the backbuffer texture", L"Fatal error.", MB_OK | MB_ICONERROR);
		return 1;
	}
	Device->CreateRenderTargetView(BackBuffer, nullptr, &renderTarget);
	BackBuffer->Release();

	ID3D11Texture2D* DepthStencilTexture = nullptr;
	D3D11_TEXTURE2D_DESC descDepth;
	descDepth.Width = 800;
	descDepth.Height = 600;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D32_FLOAT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;

	Device->CreateTexture2D(&descDepth, nullptr, &DepthStencilTexture);
	if (DepthStencilTexture == nullptr)
	{
		MessageBox(nullptr, L"Failed to create the depth stencil texture", L"Fatal error", MB_ICONERROR | MB_OK);
		return 1;
	}


	D3D11_DEPTH_STENCIL_DESC stencilDesc = { 0 };
	stencilDesc.DepthEnable = true;
	stencilDesc.StencilWriteMask = 0xFF;
	stencilDesc.StencilReadMask = 0xFF;

	stencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	stencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	stencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	stencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	stencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	ID3D11DepthStencilState* pDSState;
	Device->CreateDepthStencilState(&stencilDesc, &pDSState);

	DeviceContext->OMSetDepthStencilState(pDSState, 1);

	D3D11_DEPTH_STENCIL_VIEW_DESC DepthViewDesc;
	DepthViewDesc.Format = DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
	DepthViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	DepthViewDesc.Texture2D.MipSlice = 0;

	ID3D11DepthStencilView* DepthStencilView;
	Device->CreateDepthStencilView(DepthStencilTexture, &DepthViewDesc, &DepthStencilView);

	DeviceContext->OMSetRenderTargets(1, &renderTarget, DepthStencilView);

	D3D11_VIEWPORT Viewport;
	memset(&Viewport, 0, sizeof(D3D11_VIEWPORT));
	Viewport.TopLeftX = 0;
	Viewport.TopLeftY = 0;
	Viewport.Width = 800;
	Viewport.Height = 600;
	DeviceContext->RSSetViewports(1, &Viewport);

	ID3D11BlendState* g_pBlendStateNoBlend = NULL;

	D3D11_BLEND_DESC BlendState;
	ZeroMemory(&BlendState, sizeof(D3D11_BLEND_DESC));
	BlendState.RenderTarget[0].BlendEnable = TRUE;
	BlendState.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	Device->CreateBlendState(&BlendState, &g_pBlendStateNoBlend);

	float ClearColor[4] = { 0,0,0,1 };

	if (renderTarget == nullptr)
	{
		MessageBox(nullptr, L"Cannot create render target.", L"Fatal error!", MB_ICONERROR | MB_OK);
		return 1;
	}
	
	D3D11_QUERY_DESC queryDesc;
	ZeroMemory(&queryDesc, sizeof(D3D11_QUERY_DESC));
	ID3D11Query* query = nullptr;
	Device->CreateQuery(&queryDesc,&query);
	if (query == nullptr)
	{
		MessageBox(nullptr, L"Failed to create the ID3D11Query instance", L"Fatal error", MB_OK | MB_ICONERROR);
		return 1;
	}

	MView = _3DRadSpaceDll::Matrix::CreateLookAt(_3DRadSpaceDll::Vector3(5), _3DRadSpaceDll::Vector3(0), _3DRadSpaceDll::Vector3(0, 1, 0));
	MProjetion = _3DRadSpaceDll::Matrix::CreateProjectionFieldOfView(_3DRadSpaceDll::Math::ToRadians(65), 800.0f / 600.0f, 0.1f, 500.0f);

	char axis_file_buff[MAX_PATH];

	GetCurrentDirectoryA(MAX_PATH, axis_file_buff);
	strcat_s(axis_file_buff, "\\EngineData\\Axis.x");

	_3DRadSpaceDll::Model3D AxisModel;
	if (AxisModel.InitializeFromFileBasic(axis_file_buff) == false)
	{
		MessageBox(nullptr, L"Error loading file EngineData\\Axis.x", L"Error loading resource", MB_OK | MB_ICONERROR);
		return 1;
	}

	ID3DBlob* basicVShaderBlob = nullptr;
	D3DReadFileToBlob(L"BasicVertexShader.cso", &basicVShaderBlob);
	ID3D11VertexShader* basicVShader;
	Device->CreateVertexShader(basicVShaderBlob->GetBufferPointer(), basicVShaderBlob->GetBufferSize(), nullptr, &basicVShader);
	
	ID3D11PixelShader* basicPShaderDr = nullptr;
	ID3DBlob* basicPShaderDrBlob = nullptr;
	D3DReadFileToBlob(L"BasicPixelShader.cso", &basicPShaderDrBlob);
	Device->CreatePixelShader(basicPShaderDrBlob->GetBufferPointer(), basicPShaderDrBlob->GetBufferSize(), nullptr, &basicPShaderDr);

	D3D11_BUFFER_DESC shader_buff_desc;
	ZeroMemory(&shader_buff_desc, sizeof(D3D11_BUFFER_DESC));
	shader_buff_desc.ByteWidth = sizeof(CameraBuffer);
	shader_buff_desc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
	shader_buff_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	CameraBuffer MainCameraBuffer = { (DirectX::XMMATRIX)_3DRadSpaceDll::Matrix::CreateTranslation(_3DRadSpaceDll::Vector3(0)),
	(DirectX::XMMATRIX)MView,(DirectX::XMMATRIX)MProjetion};

	ID3D11Buffer* shader_buff;
	Device->CreateBuffer(&shader_buff_desc, nullptr, &shader_buff);
	if (shader_buff == nullptr)
	{
		MessageBox(nullptr, L"Failed to create the shader params buffer", L"Error", MB_OK | MB_ICONERROR);
		return 1;
	}

	MSG msg = { 0 };
	while (Wopen)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, 1))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//DeviceContext->Begin(query);
		DeviceContext->ClearRenderTargetView(renderTarget, ClearColor);

		MainCameraBuffer = { (DirectX::XMMATRIX)_3DRadSpaceDll::Matrix::CreateTranslation(_3DRadSpaceDll::Vector3(0)),
	(DirectX::XMMATRIX)MView,(DirectX::XMMATRIX)MProjetion };

		DeviceContext->UpdateSubresource(shader_buff,0,nullptr,&MainCameraBuffer,0,0);
		DeviceContext->VSSetShader(basicVShader, nullptr, 0);
		DeviceContext->VSSetConstantBuffers(0, 1, &shader_buff);
		DeviceContext->PSSetShader(basicPShaderDr, nullptr, 0);
		AxisModel.Draw(_3DRadSpaceDll::Matrix::CreateTranslation(_3DRadSpaceDll::Vector3(0, 0, 0)), MView, MProjetion, DeviceContext);

		//DeviceContext->End(query);
		SwapChain->Present(1, 0);
	}

	return 1;
}

LRESULT CALLBACK DrawWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
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
		break;
	}
	default: break;
	}
	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		Wopen = false;
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, window_color_brush);
		EndPaint(hwnd, &ps);
		break;
	}
	case WM_SIZE:
	{
		ResizeWindow();
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			//File -> ...
		case MENUF_NEWPROJ:
			Objects.clear();
			break;
		case MENUF_OPENPROJ:
		{
			wchar_t dir[260];
			wchar_t file[260];
			ZeroMemory(dir, 260);
			ZeroMemory(file, 260);

			OPENFILENAME openproj;
			memset(&openproj, 0, sizeof(openproj));

			openproj.lStructSize = sizeof(openproj);
			openproj.hwndOwner = MainWindow;
			openproj.lpstrFilter = OPN_FILTER_PROJECT;
			openproj.lpstrTitle = L"Open a 3DRadSpace project...";
			openproj.nMaxFile = MAX_PATH;
			openproj.lpstrFile = file;

			GetCurrentDirectory(MAX_PATH, dir);
			lstrcat(dir, L"\\Projects\\");

			openproj.lpstrInitialDir = dir;
			openproj.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&openproj))
			{
				MessageBox(nullptr, file, L"Aaand the selected file is:", MB_OK | MB_ICONINFORMATION);
			}
			break;
		}
		case MENUF_SAVEPROJ:
			SaveProject();
			break;
		case MENUF_SAVEPROJAS:
		{
			SaveProjectAs();
			break;
		}
		case MENUF_PLAY:
			ShellExecute(nullptr, nullptr, L"3DRadSpacePlayer.exe", nullptr, nullptr, SW_NORMAL);
			break;
		case MENUF_COMPILE:
			break;
		case MENUF_EXIT:
			Wopen = false;
			exit(0);
		case MENUE_ADDOBJ:
			break;
		case MENUE_ADDADD:
		{
			//Personal note: Yes, I'm reusing code without using a function lol. Should fix this an other time.
			wchar_t dir[260];
			wchar_t file[260];
			ZeroMemory(dir, 260);
			ZeroMemory(file, 260);

			OPENFILENAME openproj;
			memset(&openproj, 0, sizeof(openproj));

			openproj.lStructSize = sizeof(openproj);
			openproj.hwndOwner = MainWindow;
			openproj.lpstrFilter = OPN_FILTER_PROJECT;
			openproj.lpstrTitle = L"Open a 3DRadSpace project...";
			openproj.nMaxFile = MAX_PATH;
			openproj.lpstrFile = file;

			GetCurrentDirectory(MAX_PATH, dir);
			lstrcat(dir, L"\\Projects\\");

			openproj.lpstrInitialDir = dir;
			openproj.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&openproj))
			{
				MessageBox(nullptr, file, L"Aaand the selected file is:", MB_OK | MB_ICONINFORMATION);
			}
			break;
		}
			case MENUE_IMPORTRES:
			{
				wchar_t file[MAX_PATH],dir[MAX_PATH];
				OPENFILENAME ofn;
				ZeroMemory(&ofn, sizeof(ofn));
				ofn.lStructSize = sizeof(ofn);
				ofn.hwndOwner = MainWindow;
				ofn.lpstrFilter = OPN_FILTER_RESOURCE;
				ofn.lpstrFile = file;
				ofn.nMaxFile = MAX_PATH;
				ofn.lpstrTitle = L"Import a resource.";
				GetCurrentDirectory(MAX_PATH, dir);
				lstrcat(dir, L"\\Projects\\");
				ofn.lpstrInitialDir = dir;
				ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
				if (GetOpenFileName(&ofn))
				{
					//copy file and stuff
				}
				break;
			}
			case MENUE_RESETCURSOR:
				break;
			case MENUO_SETTINGS:
				break;
			case MENUO_CHECKFORUPDATE:
				break;
			case MENUH_ABOUT:
				break;
			case MENUH_DOCS:
				ShellExecute(MainWindow, nullptr, L"https://3dradspace.tk/Wiki", nullptr, nullptr, SW_SHOWNORMAL);
				break;
			case MENUH_FORUM:
				ShellExecute(MainWindow, nullptr, L"https://3dradspace.tk/Forum", nullptr, nullptr, SW_SHOWNORMAL);
				break;
			case MENUH_REPORTBUG:
				//todo: propably insert github link?
				ShellExecute(MainWindow, nullptr, L"https://3dradspace.tk/Forum/index.php?board=9.0", nullptr, nullptr, SW_SHOWNORMAL);
				break;
			case MENUH_WEBSITE:
				ShellExecute(nullptr, nullptr, L"https://3dradspace.tk/", nullptr, nullptr, SW_SHOWNORMAL);
				break;
			case MENUC_EDITOBJ:

				break;
			case MENUC_DELETEOBJ:

				break;
			default: break;
		}
		break;
	}
	case WM_NOTIFY:
	{
		if ((((LPNMHDR)lParam)->hwndFrom) == hObjectsList)
		{
			switch (((LPNMHDR)lParam)->code)
			{
				case NM_RCLICK:
				{
					NMITEMACTIVATE* nmia = (NMITEMACTIVATE*)lParam;
					if (nmia->iItem != -1)
					{
						POINT p;
						GetCursorPos(&p);
						HMENU hPopupMenu = CreatePopupMenu();
						InsertMenu(hPopupMenu, 0, MF_BYPOSITION | MF_STRING, MENUC_EDITOBJ, L"Edit object");
						InsertMenu(hPopupMenu, 1, MF_BYPOSITION | MF_STRING, MENUC_DELETEOBJ, L"Delete object");
						SetForegroundWindow(hwnd);
						TrackPopupMenu(hPopupMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN, p.x, p.y, 0, hwnd, nullptr);
					}
				}
				default: break;
			}
		}
	}
	return 0;

	}
	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

void ResizeWindow()
{
	RECT wr = { 0 };
	GetWindowRect(MainWindow, &wr);
	//todo: resize other controls
	int width = wr.right - wr.left;
	int height = wr.bottom - wr.top;
	SetWindowPos(hObjectsList, (HWND)0, 0, 29, 150, height - 25, SWP_SHOWWINDOW);
	SetWindowPos(DrawWindow, (HWND)0, 150, 29, width - 150, height, SWP_SHOWWINDOW);
	SetWindowPos(hToolbar, (HWND)0, 0, 0, width, 30, SWP_SHOWWINDOW);
}

BOOL DirectoryExists(LPCTSTR szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

void CreateDirectoryIfExists(LPCWSTR path)
{
	if (!DirectoryExists(path)) CreateDirectory(path,nullptr);
}

void SaveProject()
{
	if (lstrlen(LastFile) > 0) SaveProjectFile(LastFile);
	else SaveProjectAs();
}

void SaveProjectAs()
{
	wchar_t file[MAX_PATH];
	ZeroMemory(file, MAX_PATH);

	wchar_t dir[MAX_PATH];
	ZeroMemory(dir, MAX_PATH);

	GetCurrentDirectory(MAX_PATH, dir);
	lstrcat(dir, L"\\Projects\\");

	OPENFILENAME opn;
	memset(&opn, 0, sizeof(opn));

	opn.lStructSize = sizeof(opn);
	opn.lpstrFile = file;
	opn.nMaxFile = MAX_PATH;
	opn.hwndOwner = MainWindow;
	opn.lpstrFilter = OPN_FILTER_PROJECT;
	opn.lpstrInitialDir = dir;
	opn.lpstrTitle = L"Save a 3DRadSpace project...";
	opn.Flags = OFN_OVERWRITEPROMPT | OFN_EXPLORER;

	if (GetSaveFileName(&opn))
	{
		SaveProjectFile(file);
		memcpy_s(LastFile,MAX_PATH, file, MAX_PATH);
		MessageBox(nullptr, L"Saved stuff", L"OK", MB_OK);
	}
}

void SaveProjectFile(wchar_t* path)
{
	Saved = true;
	//TODO: Insert code that saves the file
}

void CreateProjectsFolder()
{
	wchar_t dir[255];
	GetCurrentDirectory(255, dir);
	lstrcat(dir, L"\\Projects\\");
	CreateDirectoryIfExists(dir);
}

void AddItem(wchar_t *Item)
{
	LVITEM item;
	memset(&item, 0, sizeof(LVITEM));
	item.mask = LVIF_TEXT | PRF_CHECKVISIBLE;
	item.pszText = Item;
	ListView_InsertItem(hObjectsList, &item);
}