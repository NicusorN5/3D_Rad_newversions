#pragma once
#include <d3d11.h>
#include <d3d.h>
#include <d3d9.h>
#include <DirectXMath.h>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) GameObject
	{
	public:
		GameObject() : Name(nullptr), Enabled(false), Position() {};
		char* Name;
		bool Enabled;
		D3DVECTOR* Position;
		float** M;
		void a()
		{

		}
	};
}
