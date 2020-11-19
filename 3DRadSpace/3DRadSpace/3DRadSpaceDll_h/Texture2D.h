#pragma once
#include "Vector2.h"
#include <d3d11.h>
#include "WICTextureLoader.h"

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Texture2D
	{
		ID3D11Device* _dev;
		ID3D11DeviceContext* _dev_context;
		Texture2D() : Texture(nullptr) , _dev(nullptr) ,_dev_context(nullptr) {};
	public:
		ID3D11Texture2D* Texture;
		static Texture2D* FromFile(wchar_t* path, ID3D11Device* _graphics_device, ID3D11DeviceContext* dev_context);
		static Texture2D* FromFile(const wchar_t* path, ID3D11Device* _graphics_device, ID3D11DeviceContext* dev_context);
	};
}

