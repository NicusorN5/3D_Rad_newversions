#pragma once
namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Math
	{
	public:
		static float Lerp(float a, float b, float q);
		static float LerpPrecise(float a, float b, float q);
	};
}

