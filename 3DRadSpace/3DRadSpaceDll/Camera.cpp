#include "pch.h"
#include "Camera.h"

_3DRadSpaceDll::Camera::Camera(char* name, bool enabled,const Vector3 &pos,const Vector3 &rotation,const Vector3 &up, float aspect_ratio, float fov, float near_d, float far_d)
{
	Name = name;
	Enabled = enabled;

	Projection = Matrix::CreateProjectionFieldOfView(fov, aspect_ratio, near_d, far_d);
	Vector3 targ = pos;
	View = Matrix::CreateLookAt(pos, rotation, up);
	Vector3 a = { 0,0,1 };
	a.Transform(Matrix::CreateFromEulerAngles(rotation));
	_rotation = a;
	AspectRatio = aspect_ratio;
	FOV = fov;
	NearPlaneDistance = near_d;
	FarPlaneDistance = far_d;
}

void _3DRadSpaceDll::Camera::Initialize(ID3D11Device* dev, ID3D11DeviceContext* context)
{
	//this->_device = dev;
}

void _3DRadSpaceDll::Camera::Update(float dt)
{
	View = Matrix::CreateLookAt(Position,Position+ _rotation,Up);
	Projection = Matrix::CreateProjectionFieldOfView(FOV, AspectRatio, NearPlaneDistance, FarPlaneDistance);
}

void _3DRadSpaceDll::Camera::Draw()
{
	View = Matrix::CreateLookAt(Position, Position + _rotation, Up);
	Projection = Matrix::CreateProjectionFieldOfView(FOV, AspectRatio, NearPlaneDistance, FarPlaneDistance);
}

_3DRadSpaceDll::Camera::~Camera()
{
	//No dynamically allocated resources. Nothing to do. Bye.
}

std::istream& _3DRadSpaceDll::operator>>(std::istream& in, const _3DRadSpaceDll::Camera& cam)
{
	in >> cam.Name >> cam.Position >> cam._rotation;
	return in;
}

std::ostream& _3DRadSpaceDll::operator<<(std::ostream& out, const _3DRadSpaceDll::Camera& cam)
{
	out << cam.Name << cam.Position << cam._rotation;
	return out;
}
