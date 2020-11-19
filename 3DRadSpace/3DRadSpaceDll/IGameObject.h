#pragma once
#include <d3d11.h>
#include <d3d.h>
#include <d3d9.h>
#include "Vector3.h"
#include "Quaternion.h"

namespace _3DRadSpaceDll
{
	/*
	 Base class for all `game-objects` in 3DRadSpace
	*/
	class __declspec(dllexport) IGameObject
	{
		ID3D11Device* _device;
		ID3D11DeviceContext *_devcontext;
	public:
		IGameObject() : Name(nullptr), Enabled(false),Position(0),Rotation(),Scale(1),_device(nullptr),_devcontext(nullptr) {};
		char* Name;
		bool Enabled;
		Vector3 Position;
		Quaternion Rotation;
		Vector3 Scale;

		virtual void Initialize(ID3D11Device* dev, ID3D11DeviceContext* context) = 0;
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual ~IGameObject() {};
	};
}
