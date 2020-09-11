#include "pch.h"
#include "Vector3.h"

float _3DRadSpaceDll::Vector3::Length()
{
    return sqrtf((X * X) + (Y * Y) + (Z * Z));
}

float _3DRadSpaceDll::Vector3::Length(Vector3 *v)
{
    return sqrtf((v->X * v->X) + (v->Y * v->Y) + (v->Z * v->Z));
}

float _3DRadSpaceDll::Vector3::LengthSquared()
{
    return (X * X) + (Y * Y) + (Z * Z);
}

float _3DRadSpaceDll::Vector3::LengthSquared(Vector3* v)
{
    return (v->X * v->X) + (v->Y * v->Y) + (v->Z * v->Z);
}

void _3DRadSpaceDll::Vector3::Normalize()
{
    X /= Length();
    Y /= Length();
    Z /= Length();
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::Normalize(Vector3 *v)
{
    float l = v->Length();
    return Vector3(v->X / l, v->Y / l, v->Z / l);
}

float _3DRadSpaceDll::Vector3::Dot(Vector3 *v)
{
    return X * v->X + Y * v->Y + v->Z * Z;
}

float _3DRadSpaceDll::Vector3::Dot(Vector3* a,Vector3* b)
{
    return 0.0f;
}

void _3DRadSpaceDll::Vector3::Cross(Vector3* v)
{
    X = Y * v->Z - v->Y * Z;
    Y = -(X * v->Z - v->X * Z);
    Z = X * v->Y - v->X * Y;
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::Cross(Vector3* a, Vector3* b)
{
    float x = a->Y * b->Z - b->Y * a->Z;
    float y = -(a->X * b->Z - b->X * a->Z);
    float z = a->X * b->Y - b->X * a->Y;
    return Vector3(x, y, z);
}

float _3DRadSpaceDll::Vector3::Distance(Vector3* v)
{
    return sqrtf((X - v->X) * (X - v->X) +
        (Y - v->Y) * (Y - v->Y) +
        (Z - v->Z) * (Z - v->Z));
}

float _3DRadSpaceDll::Vector3::Distance(Vector3* a, Vector3* b)
{
    return  sqrtf((a->X - b->X) * (a->X - b->X) +
        (a->Y - b->Y) * (a->Y - b->Y) +
        (a->Z - b->Z) * (a->Z - b->Z));
}

float _3DRadSpaceDll::Vector3::DistanceSquared(Vector3* v)
{
    return (X - v->X) * (X - v->X) +
        (Y - v->Y) * (Y - v->Y) +
        (Z - v->Z) * (Z - v->Z);
}

float _3DRadSpaceDll::Vector3::DistanceSquared(Vector3* a, Vector3* b)
{
    return  (a->X - b->X) * (a->X - b->X) +
        (a->Y - b->Y) * (a->Y - b->Y) +
        (a->Z - b->Z) * (a->Z - b->Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator+(const Vector3 &v)
{
    return Vector3(X + v.X, Y + v.Y, Z + v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator+=(const Vector3& v)
{
    return Vector3(X + v.X, Y + v.Y, Z + v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator-(const Vector3& v)
{
    return Vector3(X - v.X, Y - v.Y, Z - v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator-=(const Vector3& v)
{
    return Vector3(X - v.X, Y - v.Y, Z - v.Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator+()
{
    return Vector3(+X,+Y,+Z);
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::operator-()
{
    return Vector3(-X,-Y,-Z);
}
