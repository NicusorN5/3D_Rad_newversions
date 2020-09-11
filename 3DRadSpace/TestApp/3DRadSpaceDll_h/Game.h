#pragma once
#include <d3d11.h>
namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Game
	{
	public:
		Game(HWND hwnd);
		Game (const Game&) = delete;
		Game& operator =(const Game&) = delete;
		
		void Draw();
		void Update();

		ID3D11Device* GetDevice();
		IDXGISwapChain* GetSwapChain();
		ID3D11DeviceContext* GetDeviceContext();

		~Game();
	private:
		ID3D11Device* _device;
		IDXGISwapChain* _swapchain;
		ID3D11DeviceContext* _devicecontext;
	};
}
