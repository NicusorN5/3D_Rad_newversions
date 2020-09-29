#include "pch.h"
#include "Game.h"
#pragma comment(lib,"d3d11.lib")

_3DRadSpaceDll::Game::Game(HWND hwnd)
{

	_device = nullptr;
	_swapchain = nullptr;
	_devicecontext = nullptr;

	DXGI_SWAP_CHAIN_DESC SwapChain;
	memset(&SwapChain, 0, sizeof(SwapChain));
	SwapChain.Windowed = TRUE;
	//SwapChain.SwapEffect = DXGI_SWAP_EFFECT::DXGI_SWAP_EFFECT_DISCARD;
	SwapChain.BufferDesc.Width = 800;
	SwapChain.BufferDesc.Height = 600;
	SwapChain.BufferDesc.Format = DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	SwapChain.BufferDesc.RefreshRate.Denominator = 60;
	SwapChain.BufferDesc.RefreshRate.Numerator = 1;
	SwapChain.BufferDesc.Scaling = DXGI_MODE_SCALING::DXGI_MODE_SCALING_STRETCHED;
	//SwapChain.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	SwapChain.SampleDesc.Count = 1;
	SwapChain.SampleDesc.Quality = 0;
	SwapChain.OutputWindow = hwnd;
	SwapChain.Flags = 0;
	SwapChain.BufferCount = 1;
	SwapChain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

	D3D_FEATURE_LEVEL lvls[] =
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_1
	};

	try
	{
		HRESULT a = D3D11CreateDeviceAndSwapChain(
			nullptr, //adapter,
			D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&SwapChain,
			&_swapchain,
			&_device,
			nullptr,
			&_devicecontext
		);
		
		if (FAILED(a))
		{
			void* b = new wchar_t[100];
			LPCWSTR err = L"Failed to create D3D11Device and Swap chain. \n %02X";
			LPWSTR res = reinterpret_cast<LPWSTR>(b);
			wsprintfW(res, err, a);
			MessageBox(nullptr, res, L"Fatal error!", MB_OK | MB_ICONERROR);
			delete[] b;
		}
	}
	catch (...)
	{
		OutputDebugString(L"Failed to initialize D3D11DEVICE :(");
	}
}

void _3DRadSpaceDll::Game::Draw()
{
}

void _3DRadSpaceDll::Game::Update()
{
}

ID3D11Device* _3DRadSpaceDll::Game::GetDevice()
{
	return _device;
}

IDXGISwapChain* _3DRadSpaceDll::Game::GetSwapChain()
{
	return _swapchain;
}

ID3D11DeviceContext* _3DRadSpaceDll::Game::GetDeviceContext()
{
	return _devicecontext;
}

_3DRadSpaceDll::Game::~Game()
{
}
