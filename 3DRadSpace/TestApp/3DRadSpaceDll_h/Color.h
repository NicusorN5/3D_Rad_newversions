#pragma once
#include <cstdint>

namespace _3DRadSpaceDll
{
	struct Color
	{
		Color(float x, float y, float z) : X(x), Y(y), Z(z),A(1) {};
		Color(float x, float y, float z, float w) : X(x), Y(y), Z(z), A(w) {};
		float X, Y, Z,A;
		static Color FromRGB(const uint8_t &r,const uint8_t &g,const uint8_t &b);
	};
	
	namespace Colors
	{
		static Color Red = Color(1, 0, 0);
		static Color Greed = Color(0, 1, 0);
		static Color Blue = Color(0, 0, 1);
		static Color Black = Color(0, 0, 0);
		static Color White = Color(1, 1, 1);
		//TODO: ADD more colors
	}
}