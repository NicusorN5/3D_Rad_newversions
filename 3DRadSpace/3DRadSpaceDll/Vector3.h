#pragma once
#include <windows.h>
#include "DllExp.h"

namespace _3DRadSpaceDll
{
	struct _declspec(dllexport) Vector3
	{
	public:
		float X;
		float Y;
		float Z;
		Vector3(): X(0), Y(0), Z(0) {};
		Vector3(float u) : X(u), Y(u), Z(u) {};
		Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {};
		Vector3 operator +(Vector3 v);
		Vector3 operator +=(Vector3 v);
		Vector3 operator -(Vector3 v);
		Vector3 operator-();
		void a()
		{
		}
	};
}
