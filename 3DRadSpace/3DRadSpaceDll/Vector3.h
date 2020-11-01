#pragma once
#include <math.h>
#include <DirectXMath.h>
#include "Matrix.h"
#include <istream>
namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Matrix;
	struct __declspec(dllexport) Vector3
	{
		float X;
		float Y;
		float Z;

		Vector3() : X(0), Y(0), Z(0) {};
		Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {};
		Vector3(float f) : X(f), Y(f), Z(f) {};
		Vector3(float x, float y) : X(x), Y(y), Z(0) {};

		float Length(void);
		static float Length(const Vector3 &v);

		float LengthSquared();
		static float LengthSquared(const Vector3 &v);
		
		void Normalize();
		static Vector3 Normalize(const Vector3 &v);
	
		float Dot(const Vector3 &v);
		static float Dot(const Vector3 &a,const Vector3 &b);

		void Cross(const Vector3 &v);
		static Vector3 Cross(const Vector3 &a, const Vector3 &b);

		float Distance(const Vector3 &v);
		static float Distance(const Vector3 &a, const Vector3 &b);

		float DistanceSquared(const Vector3 &v);
		static float DistanceSquared(const Vector3 &a, const Vector3 &b);

		const Vector3& operator +(const Vector3& v) const;
		const Vector3& operator +=(const Vector3& v) const;
		const Vector3& operator -(const Vector3& v)const ;
		const Vector3& operator -=(const Vector3& v) const;

		const Vector3& operator *(const float& s) const;
		const Vector3& operator *=(const float& s) const;
		const Vector3& operator /(const float& s) const;
		const Vector3& operator /=(const float& s) const;

		const Vector3& operator+() const;
		const Vector3& operator-() const;

		operator DirectX::XMVECTORF32();

		void Transform(const Matrix &m);

		const Vector3& operator =(const Vector3& v) const;

		friend std::istream& operator>>(std::istream& in, const Vector3& vec);
		friend std::ostream& operator<<(std::ostream& out, const Vector3& vec);
	};
	std::istream& operator>>(std::istream& in, const Vector3& vec);
	std::ostream& operator<<(std::ostream& out, const Vector3& vec);
}
