#include "pch.h"
#include "Vector3.h"

float _3DRadSpaceDll::Vector3::Length(void)
{
    return sqrtf((X * X) + (Y * Y) + (Z * Z));
}

float _3DRadSpaceDll::Vector3::Length(const Vector3 &v)
{
    return sqrtf((v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z));
}

float _3DRadSpaceDll::Vector3::LengthSquared()
{
    return (X * X) + (Y * Y) + (Z * Z);
}

float _3DRadSpaceDll::Vector3::LengthSquared(const Vector3 &v)
{
    return (v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z);
}

void _3DRadSpaceDll::Vector3::Normalize()
{
    (*this) /= this->Length();
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::Normalize(const Vector3 &v)
{
    float l = Vector3::Length(v);
    return Vector3(v.X / l, v.Y / l, v.Z / l);
}

float _3DRadSpaceDll::Vector3::Dot(const Vector3 &v)
{
    return X * v.X + Y * v.Y + v.Z * Z;
}

float _3DRadSpaceDll::Vector3::Dot(const Vector3 &a,const Vector3 &b)
{
    return 0.0f;
}

void _3DRadSpaceDll::Vector3::Cross(const Vector3 &v)
{
    X = Y * v.Z - v.Y * Z;
    Y = -(X * v.Z - v.X * Z);
    Z = X * v.Y - v.X * Y;
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Vector3::Cross(const Vector3 &a,const Vector3 &b)
{
    float x = a.Y * b.Z - b.Y * a.Z;
    float y = -(a.X * b.Z - b.X * a.Z);
    float z = a.X * b.Y - b.X * a.Y;
    return Vector3(x, y, z);
}

float _3DRadSpaceDll::Vector3::Distance(const Vector3 &v)
{
    return sqrtf((X - v.X) * (X - v.X) +
        (Y - v.Y) * (Y - v.Y) +
        (Z - v.Z) * (Z - v.Z));
}

float _3DRadSpaceDll::Vector3::Distance(const Vector3 &a, const Vector3 &b)
{
    return  sqrtf((a.X - b.X) * (a.X - b.X) +
        (a.Y - b.Y) * (a.Y - b.Y) +
        (a.Z - b.Z) * (a.Z - b.Z));
}

float _3DRadSpaceDll::Vector3::DistanceSquared(const Vector3 &v)
{
    return (X - v.X) * (X - v.X) +
        (Y - v.Y) * (Y - v.Y) +
        (Z - v.Z) * (Z - v.Z);
}

float _3DRadSpaceDll::Vector3::DistanceSquared(const Vector3 &a, const Vector3 &b)
{
    return  (a.X - b.X) * (a.X - b.X) +
        (a.Y - b.Y) * (a.Y - b.Y) +
        (a.Z - b.Z) * (a.Z - b.Z);
}


const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator+(const Vector3 &v) const
{
    return Vector3(X + v.X, Y + v.Y, Z + v.Z);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator+=(const Vector3& v) const
{
    return Vector3(X + v.X, Y + v.Y, Z + v.Z);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator-(const Vector3& v) const
{
    return Vector3(X - v.X, Y - v.Y, Z - v.Z);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator-=(const Vector3& v) const
{
    return Vector3(X - v.X, Y - v.Y, Z - v.Z);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator*(const float& s) const
{
    return Vector3(X*s,Y*s,Z*s);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator*=(const float& s) const
{
    return Vector3(X * s, Y * s, Z * s);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator/(const float& s) const
{
    return Vector3(X * s, Y * s, Z * s);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator/=(const float& s) const
{
    return Vector3();
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator+() const
{
    return Vector3(+X,+Y,+Z);
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator-() const
{
    return Vector3(-X,-Y,-Z);
}

_3DRadSpaceDll::Vector3::operator DirectX::XMVECTORF32()
{
    DirectX::XMVECTORF32 v;
    v.f[0] = X;
    v.f[1] = Y;
    v.f[2] = Z;
    v.f[3] = 1;
    return v;
}

void _3DRadSpaceDll::Vector3::Transform(const Matrix &m)
{
    X = (X * m.M11) + (Y * m.M21) + (Z * m.M31) + m.M41;
    Y = (X * m.M12) + (Y * m.M22) + (Z * m.M32) + m.M42;
    Z = (X * m.M13) + (Y * m.M23) + (Z * m.M33) + m.M43;
}

const _3DRadSpaceDll::Vector3& _3DRadSpaceDll::Vector3::operator=(const Vector3& v) const
{
    return Vector3(v.X, v.Y, v.Z);
}
