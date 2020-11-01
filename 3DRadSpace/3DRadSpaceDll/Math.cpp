#include "pch.h"
#include "Math.h"

float _3DRadSpaceDll::Math::Lerp(float a, float b, float q)
{
	return a + q * (b - a);
}
float _3DRadSpaceDll::Math::LerpPrecise(float a, float b, float q)
{
	return (1 - q)* a + q * a;
}

float _3DRadSpaceDll::Math::ToRadians(float degrees)
{
	return degrees * (M_PI / 180);
}
