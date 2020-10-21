#pragma once
namespace _3DRadSpaceDll
{
	struct Vector2
	{
	public:
		float X;
		float Y;
		Vector2() : X(0), Y(0) {};
		Vector2(float w) : X(w), Y(w) {};
		Vector2(float x, float y) : X(x), Y(y) {};
	};
}

