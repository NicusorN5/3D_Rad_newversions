#include "pch.h"
#include "Matrix.h"

float _3DRadSpaceDll::Matrix::Determinant()
{
    float num22 = M11;
    float num21 = M12;
    float num20 = M13;
    float num19 = M14;
    float num12 = M21;
    float num11 = M22;
    float num10 = M23;
    float num9 = M24;
    float num8 = M31;
    float num7 = M32;
    float num6 = M33;
    float num5 = M34;
    float num4 = M41;
    float num3 = M42;
    float num2 = M43;
    float num = M44;
    float num18 = (num6 * num) - (num5 * num2);
    float num17 = (num7 * num) - (num5 * num3);
    float num16 = (num7 * num2) - (num6 * num3);
    float num15 = (num8 * num) - (num5 * num4);
    float num14 = (num8 * num2) - (num6 * num4);
    float num13 = (num8 * num3) - (num7 * num4);
    return ((((num22 * (((num11 * num18) - (num10 * num17)) + (num9 * num16))) - (num21 * (((num12 * num18) - (num10 * num15)) + (num9 * num14)))) + (num20 * (((num12 * num17) - (num11 * num15)) + (num9 * num13)))) - (num19 * (((num12 * num16) - (num11 * num14)) + (num10 * num13))));
}

float _3DRadSpaceDll::Matrix::Determinant(Matrix* m)
{
    return m->Determinant();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateLookAt(Vector3* CameraPos, Vector3* CameraTarget, Vector3* Up)
{
    Matrix result;
    Vector3 a = *CameraPos - (*CameraTarget);
    Vector3 vector = Vector3::Normalize(&a);
    Vector3 vector2 = Vector3::Normalize(&(Vector3::Cross(Up, &vector)));
    Vector3 vector3 = Vector3::Cross(&vector, &vector2);
    result.M11 = vector2.X;
    result.M12 = vector3.X;
    result.M13 = vector.X;
    result.M14 = 0;
    result.M21 = vector2.Y;
    result.M22 = vector3.Y;
    result.M23 = vector.Y;
    result.M24 = 0;
    result.M31 = vector2.Z;
    result.M32 = vector3.Z;
    result.M33 = vector.Z;
    result.M34 = 0;
    result.M41 = -Vector3::Dot(&vector2, CameraPos);
    result.M42 = -Vector3::Dot(&vector3, CameraPos);
    result.M43 = -Vector3::Dot(&vector, CameraPos);
    result.M44 = 1;
    return result;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateTranslation(Vector3* tr)
{
    Matrix r;
    r.M41 = tr->X;
    r.M42 = tr->Y;
    r.M43 = tr->Z;
    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationX(float radians)
{
    return Matrix();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationY(float radians)
{
    return Matrix();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationZ(float radians)
{
    return Matrix();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateScale(float scalar)
{
    Matrix a;
    a *= scalar;
    return a;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateScale(Vector3* scale)
{
    Matrix a;
    a.M11 = scale->X;
    a.M22 = scale->Y;
    a.M33 = scale->Z;
    return a;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator*(const float& scalar)
{
    Matrix r(*this);
    r.M11 *= scalar;
    r.M12 *= scalar;
    r.M13 *= scalar;
    r.M14 *= scalar;

    r.M21 *= scalar;
    r.M22 *= scalar;
    r.M23 *= scalar;
    r.M24 *= scalar;

    r.M31 *= scalar;
    r.M32 *= scalar;
    r.M33 *= scalar;
    r.M34 *= scalar;

    r.M41 *= scalar;
    r.M42 *= scalar;
    r.M43 *= scalar;
    r.M44 *= scalar;

    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator*=(const float& scalar)
{
    //lol copypaste from above XD
    Matrix r(*this);
    r.M11 *= scalar;
    r.M12 *= scalar;
    r.M13 *= scalar;
    r.M14 *= scalar;

    r.M21 *= scalar;
    r.M22 *= scalar;
    r.M23 *= scalar;
    r.M24 *= scalar;

    r.M31 *= scalar;
    r.M32 *= scalar;
    r.M33 *= scalar;
    r.M34 *= scalar;

    r.M41 *= scalar;
    r.M42 *= scalar;
    r.M43 *= scalar;
    r.M44 *= scalar;

    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator+(const Matrix &m)
{
    Matrix r;
    r.M11 = M11 + m.M11;
    r.M12 = M12 + m.M12;
    r.M13 = M13 + m.M13;
    r.M14 = M14 + m.M14;

    r.M21 = M21 + m.M21;
    r.M22 = M22 + m.M22;
    r.M23 = M23 + m.M23;
    r.M24 = M24 + m.M24;

    r.M31 = M31 + m.M31;
    r.M32 = M32 + m.M32;
    r.M33 = M33 + m.M33;
    r.M34 = M34 + m.M34;

    r.M41 = M41 + m.M41;
    r.M42 = M42 + m.M42;
    r.M43 = M43 + m.M43;
    r.M44 = M44 + m.M44;

    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator+=(const Matrix& m)
{
    Matrix r;
    r.M11 = M11 + m.M11;
    r.M12 = M12 + m.M12;
    r.M13 = M13 + m.M13;
    r.M14 = M14 + m.M14;

    r.M21 = M21 + m.M21;
    r.M22 = M22 + m.M22;
    r.M23 = M23 + m.M23;
    r.M24 = M24 + m.M24;

    r.M31 = M31 + m.M31;
    r.M32 = M32 + m.M32;
    r.M33 = M33 + m.M33;
    r.M34 = M34 + m.M34;

    r.M41 = M41 + m.M41;
    r.M42 = M42 + m.M42;
    r.M43 = M43 + m.M43;
    r.M44 = M44 + m.M44;

    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator-(const Matrix& m)
{
    Matrix r;
    r.M11 = M11 - m.M11;
    r.M12 = M12 - m.M12;
    r.M13 = M13 - m.M13;
    r.M14 = M14 - m.M14;

    r.M21 = M21 - m.M21;
    r.M22 = M22 - m.M22;
    r.M23 = M23 - m.M23;
    r.M24 = M24 - m.M24;

    r.M31 = M31 - m.M31;
    r.M32 = M32 - m.M32;
    r.M33 = M33 - m.M33;
    r.M34 = M34 - m.M34;

    r.M41 = M41 - m.M41;
    r.M42 = M42 - m.M42;
    r.M43 = M43 - m.M43;
    r.M44 = M44 - m.M44;

    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator-=(const Matrix& m)
{
    return Matrix();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator*(const Matrix &m)
{
    Matrix r;
    r.M11 = (((M11 * m.M11) + (M12 * m.M21)) + (M13 * m.M31)) + (M14 * m.M41);
    r.M12 = (((M11 * m.M12) + (M12 * m.M22)) + (M13 * m.M32)) + (M14 * m.M42);
    r.M13 = (((M11 * m.M13) + (M12 * m.M23)) + (M13 * m.M33)) + (M14 * m.M43);
    r.M14 = (((M11 * m.M14) + (M12 * m.M24)) + (M13 * m.M34)) + (M14 * m.M44);
    r.M21 = (((M21 * m.M11) + (M22 * m.M21)) + (M23 * m.M31)) + (M24 * m.M41);
    r.M22 = (((M21 * m.M12) + (M22 * m.M22)) + (M23 * m.M32)) + (M24 * m.M42);
    r.M23 = (((M21 * m.M13) + (M22 * m.M23)) + (M23 * m.M33)) + (M24 * m.M43);
    r.M24 = (((M21 * m.M14) + (M22 * m.M24)) + (M23 * m.M34)) + (M24 * m.M44);
    r.M31 = (((M31 * m.M11) + (M32 * m.M21)) + (M33 * m.M31)) + (M34 * m.M41);
    r.M32 = (((M31 * m.M12) + (M32 * m.M22)) + (M33 * m.M32)) + (M34 * m.M42);
    r.M33 = (((M31 * m.M13) + (M32 * m.M23)) + (M33 * m.M33)) + (M34 * m.M43);
    r.M34 = (((M31 * m.M14) + (M32 * m.M24)) + (M33 * m.M34)) + (M34 * m.M44);
    r.M41 = (((M41 * m.M11) + (M42 * m.M21)) + (M43 * m.M31)) + (M44 * m.M41);
    r.M42 = (((M41 * m.M12) + (M42 * m.M22)) + (M43 * m.M32)) + (M44 * m.M42);
    r.M43 = (((M41 * m.M13) + (M42 * m.M23)) + (M43 * m.M33)) + (M44 * m.M43);
    r.M44 = (((M41 * m.M14) + (M42 * m.M24)) + (M43 * m.M34)) + (M44 * m.M44);
    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::operator*=(const Matrix &m)
{
    Matrix r;
    r.M11 = (((M11 * m.M11) + (M12 * m.M21)) + (M13 * m.M31)) + (M14 * m.M41);
    r.M12 = (((M11 * m.M12) + (M12 * m.M22)) + (M13 * m.M32)) + (M14 * m.M42);
    r.M13 = (((M11 * m.M13) + (M12 * m.M23)) + (M13 * m.M33)) + (M14 * m.M43);
    r.M14 = (((M11 * m.M14) + (M12 * m.M24)) + (M13 * m.M34)) + (M14 * m.M44);
    r.M21 = (((M21 * m.M11) + (M22 * m.M21)) + (M23 * m.M31)) + (M24 * m.M41);
    r.M22 = (((M21 * m.M12) + (M22 * m.M22)) + (M23 * m.M32)) + (M24 * m.M42);
    r.M23 = (((M21 * m.M13) + (M22 * m.M23)) + (M23 * m.M33)) + (M24 * m.M43);
    r.M24 = (((M21 * m.M14) + (M22 * m.M24)) + (M23 * m.M34)) + (M24 * m.M44);
    r.M31 = (((M31 * m.M11) + (M32 * m.M21)) + (M33 * m.M31)) + (M34 * m.M41);
    r.M32 = (((M31 * m.M12) + (M32 * m.M22)) + (M33 * m.M32)) + (M34 * m.M42);
    r.M33 = (((M31 * m.M13) + (M32 * m.M23)) + (M33 * m.M33)) + (M34 * m.M43);
    r.M34 = (((M31 * m.M14) + (M32 * m.M24)) + (M33 * m.M34)) + (M34 * m.M44);
    r.M41 = (((M41 * m.M11) + (M42 * m.M21)) + (M43 * m.M31)) + (M44 * m.M41);
    r.M42 = (((M41 * m.M12) + (M42 * m.M22)) + (M43 * m.M32)) + (M44 * m.M42);
    r.M43 = (((M41 * m.M13) + (M42 * m.M23)) + (M43 * m.M33)) + (M44 * m.M43);
    r.M44 = (((M41 * m.M14) + (M42 * m.M24)) + (M43 * m.M34)) + (M44 * m.M44);
    return r;
}

float _3DRadSpaceDll::Matrix::operator[](const int &index)
{
    switch (index)
    {
        case 0: return M11;
        case 1: return M12;
        case 2: return M13;
        case 3: return M14;

        case 4: return M21;
        case 5: return M22;
        case 6: return M23;
        case 7: return M24;
        
        case 8: return M31;
        case 9: return M32;
        case 10: return M33;
        case 11: return M34;

        case 12: return M41;
        case 13: return M42;
        case 14: return M43;
        case 15: return M44;

        default: return NAN;
    }
}
