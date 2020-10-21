#pragma once
#include "GameObject.h"

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Camera : public GameObject
	{
	public:
		Matrix View;
		Matrix Projection;

		Camera() = delete;


		Camera(char* name, bool enabled, Vector3 pos, Vector3 targ, Vector3 up, float aspect_ratio, float FOV, float near_d, float far_d);
	};
}

