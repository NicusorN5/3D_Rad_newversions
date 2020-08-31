#include "pch.h"
#include "Vector3.h"

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator+(Vector3 v)
{
    return Vector3(X+v.X,Y+v.Y,Z+v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator+=(Vector3 v)
{
    return Vector3(X + v.X, Y + v.Y, Z + v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator-(Vector3 v)
{
    return Vector3(X-v.X,Z-v.Y,Z-v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator-()
{
    return Vector3(-X,-Y,-Z);
}
