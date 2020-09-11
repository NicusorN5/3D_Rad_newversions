#pragma once
#include <math.h>
namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Vector3
	{
		float X;
		float Y;
		float Z;

		Vector3() : X(0), Y(0), Z(0) {};
		Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {};
		Vector3(float f) : X(f), Y(f), Z(f) {};
		Vector3(float x, float y) : X(x), Y(y), Z(0) {};

		float Length();
		static float Length(Vector3* v);

		float LengthSquared();
		static float LengthSquared(Vector3* v);
		
		void Normalize();
		static Vector3 Normalize(Vector3 *v);
	
		float Dot(Vector3* v);
		static float Dot(Vector3* a,Vector3* b);

		void Cross(Vector3* v);
		static Vector3 Cross(Vector3* a, Vector3* b);

		float Distance(Vector3* v);
		static float Distance(Vector3* a, Vector3* b);

		float DistanceSquared(Vector3* v);
		static float DistanceSquared(Vector3* a, Vector3* b);

		Vector3 operator +(const Vector3& v);
		Vector3 operator +=(const Vector3& v);
		Vector3 operator -(const Vector3& v);
		Vector3 operator -=(const Vector3& v);

		Vector3 operator *(const float& s);
		Vector3 operator *=(const float& s);
		Vector3 operator /(const float& s);
		Vector3 operator /=(const float& s);

		Vector3 operator+();
		Vector3 operator-();
	};
}
