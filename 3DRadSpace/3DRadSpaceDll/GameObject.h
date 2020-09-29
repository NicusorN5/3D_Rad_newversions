#pragma once
#include <d3d11.h>
#include <d3d.h>
#include <d3d9.h>
#include "Vector3.h"
#include "Quaternion.h"
#include "IGameObject.h"

namespace _3DRadSpaceDll
{
	/*
	 Base class for all `game-objects` in 3DRadSpace
	*/
	class __declspec(dllexport) GameObject : public IGameObject
	{
	public:
		GameObject() : Name(nullptr), Enabled(false),Position(0),Rotation(),Scale(1) {};
		char* Name;
		bool Enabled;
		Vector3 Position;
		Quaternion Rotation;
		Vector3 Scale;
	};
}
