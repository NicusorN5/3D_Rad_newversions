#pragma once

#include "Vector3.h"

namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Plane
	{
		struct {
			float X, Y, Z;
		} Normal;
		float Distance;
	};
}