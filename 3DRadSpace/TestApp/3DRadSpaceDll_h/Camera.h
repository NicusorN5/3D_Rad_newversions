#pragma once
#include "IGameObject.h"

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Camera : public IGameObject
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

		//Camera() = delete;

		Camera(char* name, bool enabled,const Vector3 &pos,const Vector3 &rotation,const Vector3 &up, float aspect_ratio, float fov, float near_d, float far_d);
		
		void Initialize(ID3D11Device* dev, ID3D11DeviceContext* context) override;

		void Update(float dt) override;

		void Draw() override;
	
		~Camera();

		friend std::istream& operator >>(std::istream& in, const Camera& cam);
		friend std::ostream& operator <<(std::ostream& out, const Camera& cam);
	};
}

