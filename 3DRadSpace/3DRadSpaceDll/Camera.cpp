#include "pch.h"
#include "Camera.h"

_3DRadSpaceDll::Camera::Camera(char* name, bool enabled, Vector3 pos, Vector3 rotation, Vector3 up, float aspect_ratio, float FOV, float near_d, float far_d)
{
	Name = name;
	Enabled = enabled;

	Projection = Matrix::CreateProjectionFieldOfView(FOV, aspect_ratio, near_d, far_d);
	Vector3 targ = pos;
	View = Matrix::CreateLookAt(pos, rotation, up);
	Vector3 a = { 0,0,1 };
	a.Transform(Matrix::CreateFromEulerAngles(rotation));
	_rotation = a;
}

void _3DRadSpaceDll::Camera::Update(float dt)
{
	View = Matrix::CreateLookAt(Position,Position+ _rotation,Up);
	Projection = Matrix::CreateProjectionFieldOfView(FOV, AspectRatio, NearPlaneDistance, FarPlaneDistance);
}
