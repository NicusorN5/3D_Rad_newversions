#pragma once
#include <math.h>

#define M_PI 3.1415926 //PI constant
#define M_TAU 6.2831853 //TAU constant aka 2*PI
#define M_HALF_PI 1.5707963 // PI / 2
#define M_PI_DIV_FOUR 0.7853981 // PI / 4

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

