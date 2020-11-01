#pragma once
#include <math.h>

#define M_PI 3.1416926

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Math
	{
	public:

		static float Lerp(float a, float b, float q);
		static float LerpPrecise(float a, float b, float q);
		static float ToRadians(float degrees);
	};
}

