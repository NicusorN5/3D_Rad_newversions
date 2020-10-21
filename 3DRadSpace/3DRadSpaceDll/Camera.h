#pragma once
#include "GameObject.h"

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Camera : public GameObject
	{
		Vector3 _rotation;
	public:
		Matrix View;
		Matrix Projection;

		Vector3 Up;

		float FOV;
		float AspectRatio;
		float NearPlaneDistance;
		float FarPlaneDistance;

		Camera() = delete;

		Camera(char* name, bool enabled, Vector3 pos, Vector3 rotation, Vector3 up, float aspect_ratio, float FOV, float near_d, float far_d);
		
		void Update(float dt) override;
	
	};
}

