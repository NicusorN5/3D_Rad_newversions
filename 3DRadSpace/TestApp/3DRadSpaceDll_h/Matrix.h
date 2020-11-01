#pragma once
#include <DirectXMath.h>
#include <exception>
#include "Vector3.h"
#include "Plane.h"
namespace _3DRadSpaceDll
{
	struct __declspec(dllexport) Vector3;
	struct __declspec(dllexport) Matrix
	{
	public:
		float M11, M12, M13, M14;
		float M21, M22, M23, M24;
		float M31, M32, M33, M34;
		float M41, M42, M43, M44;

		/*
		Creates an identity matrix.
		*/
		Matrix() :
			M11(1), M12(0), M13(0), M14(0),
			M21(0), M22(1), M23(0), M24(0),
			M31(0), M32(0), M33(1), M34(0),
			M41(0), M42(0), M43(0), M44(1){};
		Matrix(float m[4][4]):
			M11(m[0][0]), M12(m[0][1]), M13(m[0][2]), M14(m[0][3]),
			M21(m[1][0]), M22(m[1][1]), M23(m[1][2]), M24(m[1][3]),
			M31(m[2][0]), M32(m[2][1]), M33(m[2][2]), M34(m[2][3]),
			M41(m[3][0]), M42(m[3][1]), M43(m[3][2]), M44(m[3][3]) {};
		
		float Determinant();
		void Invert();

		//static f(x)'s
		static float Determinant(Matrix* m);

		static Matrix CreateLookAt(const Vector3 &CameraPos,const Vector3 &CameraLookAt,const Vector3 &Up);
		static Matrix CreateProjectionFieldOfView(float FOVradians, float aspect_ratio, float nearPlaneD, float farPlaneD);
		static Matrix CreateTranslation(const Vector3 &tr);
		static Matrix CreateRotationX(float radians);
		static Matrix CreateRotationY(float radians);
		static Matrix CreateRotationZ(float radians);
		static Matrix CreateFromEulerAngles(const Vector3& angl);
		static Matrix CreateScale(float scalar);
		static Matrix CreateScale(const Vector3 &scale);

		static Matrix CreateShadow(const Vector3 &lightDirection, const Plane &plane);

		//scalar operators
		Matrix operator*(const float &scalar);
		Matrix operator *=(const float &scalar);
		//matrix-matrix operators
		Matrix operator+(const Matrix &m);
		Matrix operator +=(const Matrix &m);

		Matrix operator -(const Matrix &m);
		Matrix operator -=(const Matrix &m);

		Matrix operator *(const Matrix &m);
		Matrix operator *=(const Matrix &m);

		float operator[](const int &index);
	};
};

