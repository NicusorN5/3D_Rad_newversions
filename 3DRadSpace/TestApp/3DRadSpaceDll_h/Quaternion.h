#pragma once
#include "Vector3.h"

namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Quaternion
	{
		float X;
		float Y;
		float Z;
		float W;
		Quaternion(): X(0), Y(0), Z(0), W(1) {};
		Quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {};

		static Quaternion FromEuler(const Vector3 &vector);
		static Vector3 EulerFromQuaternion(const Quaternion &q);

		Quaternion Multiply(const Quaternion &quaternion1,const Quaternion &quaternion2);
		void Normalize();
	};
}

