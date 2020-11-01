#pragma once
#include <d3d11.h>
#include <istream>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) IGameObject
	{
	public:
		virtual void Initialize(ID3D11Device* dev,ID3D11DeviceContext* context) = 0;
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual ~IGameObject() {};
	};
}

