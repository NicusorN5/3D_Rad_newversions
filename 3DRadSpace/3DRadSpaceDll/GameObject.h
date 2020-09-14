#pragma once
#include <d3d11.h>
#include <d3d.h>
#include <d3d9.h>
#include "Vector3.h"

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) GameObject
	{
	public:
		GameObject() : Name(nullptr), Enabled(false),Position(0) {};
		char* Name;
		bool Enabled;
		Vector3 Position;
		void a()
		{

		}
	};
}
