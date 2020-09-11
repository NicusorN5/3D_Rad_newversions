#include "Vector3.h"
#include <DirectXMath.h>
#include <exception>
#pragma once

namespace _3DRadSpaceDll
{
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

		float Determinant();
		static float Determinant(Matrix* m);

		Matrix CreateLookAt(Vector3* CameraPos,Vector3* CameraLookAt,Vector3* Up);
		Matrix CreateProjectionFieldOfView(float FOVradians, float aspect_ratio, float nearPlaneD, float farPlaneD);
		Matrix CreateTranslation(Vector3* tr);
		Matrix CreateRotationX(float radians);
		Matrix CreateRotationY(float radians);
		Matrix CreateRotationZ(float radians);
		Matrix CreateScale(float scalar);
		Matrix CreateScale(Vector3* scale);

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

