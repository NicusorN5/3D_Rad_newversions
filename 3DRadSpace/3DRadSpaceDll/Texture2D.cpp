#include "pch.h"
#include "Texture2D.h"

_3DRadSpaceDll::Texture2D* _3DRadSpaceDll::Texture2D::FromFile(wchar_t* path, ID3D11Device* _graphics_device,ID3D11DeviceContext* dev_context)
{
	ID3D11Resource* rTexture = nullptr;

	CreateWICTextureFromFile(_graphics_device, dev_context, path, &rTexture, nullptr);
	
	return (Texture2D*)rTexture;
}

_3DRadSpaceDll::Texture2D* _3DRadSpaceDll::Texture2D::FromFile(const wchar_t* path, ID3D11Device* _graphics_device, ID3D11DeviceContext* dev_context)
{
	ID3D11Resource* rTexture = nullptr;
	HRESULT r = CreateWICTextureFromFile(_graphics_device, dev_context, path, &rTexture, nullptr);
	if (FAILED(r)) return nullptr;
	return (Texture2D*)rTexture;
}
