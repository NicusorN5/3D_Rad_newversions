#pragma once
#include "Triangle.h"

namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Ray
	{
		Vector3 Position;
		Vector3 Direction;

		Ray(Vector3 p, Vector3 dir) : Position(p), Direction(dir) {};

		Vector3* IntersectsTriangle(const Triangle& triangle);
	};
}

