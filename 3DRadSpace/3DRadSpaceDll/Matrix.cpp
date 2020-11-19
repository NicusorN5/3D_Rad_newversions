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

void _3DRadSpaceDll::Matrix::Invert()
{
    float num1 = M11;
    float num2 = M12;
    float num3 = M13;
    float num4 = M14;
    float num5 = M21;
    float num6 = M22;
    float num7 = M23;
    float num8 = M24;
    float num9 = M31;
    float num10 = M32;
    float num11 = M33;
    float num12 = M34;
    float num13 = M41;
    float num14 = M42;
    float num15 = M43;
    float num16 = M44;
    float num17 = (float)((double)num11 * (double)num16 - (double)num12 * (double)num15);
    float num18 = (float)((double)num10 * (double)num16 - (double)num12 * (double)num14);
    float num19 = (float)((double)num10 * (double)num15 - (double)num11 * (double)num14);
    float num20 = (float)((double)num9 * (double)num16 - (double)num12 * (double)num13);
    float num21 = (float)((double)num9 * (double)num15 - (double)num11 * (double)num13);
    float num22 = (float)((double)num9 * (double)num14 - (double)num10 * (double)num13);
    float num23 = (float)((double)num6 * (double)num17 - (double)num7 * (double)num18 + (double)num8 * (double)num19);
    float num24 = (float)-((double)num5 * (double)num17 - (double)num7 * (double)num20 + (double)num8 * (double)num21);
    float num25 = (float)((double)num5 * (double)num18 - (double)num6 * (double)num20 + (double)num8 * (double)num22);
    float num26 = (float)-((double)num5 * (double)num19 - (double)num6 * (double)num21 + (double)num7 * (double)num22);
    float num27 = (float)(1.0 / ((double)num1 * (double)num23 + (double)num2 * (double)num24 + (double)num3 * (double)num25 + (double)num4 * (double)num26));

    M11 = num23 * num27;
    M21 = num24 * num27;
    M31 = num25 * num27;
    M41 = num26 * num27;
    M12 = (float)-((double)num2 * (double)num17 - (double)num3 * (double)num18 + (double)num4 * (double)num19) * num27;
    M22 = (float)((double)num1 * (double)num17 - (double)num3 * (double)num20 + (double)num4 * (double)num21) * num27;
    M32 = (float)-((double)num1 * (double)num18 - (double)num2 * (double)num20 + (double)num4 * (double)num22) * num27;
    M42 = (float)((double)num1 * (double)num19 - (double)num2 * (double)num21 + (double)num3 * (double)num22) * num27;
    float num28 = (float)((double)num7 * (double)num16 - (double)num8 * (double)num15);
    float num29 = (float)((double)num6 * (double)num16 - (double)num8 * (double)num14);
    float num30 = (float)((double)num6 * (double)num15 - (double)num7 * (double)num14);
    float num31 = (float)((double)num5 * (double)num16 - (double)num8 * (double)num13);
    float num32 = (float)((double)num5 * (double)num15 - (double)num7 * (double)num13);
    float num33 = (float)((double)num5 * (double)num14 - (double)num6 * (double)num13);
    M13 = (float)((double)num2 * (double)num28 - (double)num3 * (double)num29 + (double)num4 * (double)num30) * num27;
    M23 = (float)-((double)num1 * (double)num28 - (double)num3 * (double)num31 + (double)num4 * (double)num32) * num27;
    M33 = (float)((double)num1 * (double)num29 - (double)num2 * (double)num31 + (double)num4 * (double)num33) * num27;
    M43 = (float)-((double)num1 * (double)num30 - (double)num2 * (double)num32 + (double)num3 * (double)num33) * num27;
    float num34 = (float)((double)num7 * (double)num12 - (double)num8 * (double)num11);
    float num35 = (float)((double)num6 * (double)num12 - (double)num8 * (double)num10);
    float num36 = (float)((double)num6 * (double)num11 - (double)num7 * (double)num10);
    float num37 = (float)((double)num5 * (double)num12 - (double)num8 * (double)num9);
    float num38 = (float)((double)num5 * (double)num11 - (double)num7 * (double)num9);
    float num39 = (float)((double)num5 * (double)num10 - (double)num6 * (double)num9);
    M14 = (float)-((double)num2 * (double)num34 - (double)num3 * (double)num35 + (double)num4 * (double)num36) * num27;
    M24 = (float)((double)num1 * (double)num34 - (double)num3 * (double)num37 + (double)num4 * (double)num38) * num27;
    M34 = (float)-((double)num1 * (double)num35 - (double)num2 * (double)num37 + (double)num4 * (double)num39) * num27;
    M44 = (float)((double)num1 * (double)num36 - (double)num2 * (double)num38 + (double)num3 * (double)num39) * num27;
}

float _3DRadSpaceDll::Matrix::Determinant(Matrix* m)
{
    return m->Determinant();
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateLookAt(const Vector3& CameraPos, const Vector3& CameraLookAt, const Vector3& Up)
{
    Matrix result;
    Vector3 a = CameraPos - CameraLookAt;
    Vector3 vector = Vector3::Normalize(a);
    Vector3 vector2 = Vector3::Normalize(Vector3::Cross(Up, vector));
    Vector3 vector3 = Vector3::Cross(vector, vector2);
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
    result.M41 = -Vector3::Dot(vector2, CameraPos);
    result.M42 = -Vector3::Dot(vector3, CameraPos);
    result.M43 = -Vector3::Dot(vector, CameraPos);
    result.M44 = 1;
    return result;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateProjectionFieldOfView(float FOVradians, float aspect_ratio, float nearPlaneD, float farPlaneD)
{
    Matrix r;
    //error checking
    if ((FOVradians <= 0.0f) || (FOVradians >= 3.141593f))
    {
        throw std::exception("FOVRadians <= 0 or FOVRadians >= PI (out of range)");
    }
    if (nearPlaneD <= 0.0f)
    {
        throw std::exception("nearPlaneDistance <= 0");
    }
    if (farPlaneD <= 0.0f)
    {
        throw std::exception("farPlaneDistance <= 0");
    }
    if (nearPlaneD >= farPlaneD)
    {
        throw std::exception("nearPlaneDistance >= farPlaneDistance");
    }
    //create matrix
    float num = 1.0f / (tanf(FOVradians * 0.5f));
    float num9 = num / aspect_ratio;
    r.M11 = num9;
    r.M12 = r.M13 = r.M14 = 0;
    r.M22 = num;
    r.M21 = r.M23 = r.M24 = 0;
    r.M31 = r.M32 = 0.0f;
    r.M33 = farPlaneD / (nearPlaneD - farPlaneD);
    r.M34 = -1;
    r.M41 = r.M42 = r.M44 = 0;
    r.M43 = (nearPlaneD * farPlaneD) / (nearPlaneD - farPlaneD);
    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateTranslation(const Vector3 &tr)
{
    Matrix r;
    r.M41 = tr.X;
    r.M42 = tr.Y;
    r.M43 = tr.Z;
    return r;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationX(float radians)
{
    Matrix result;

    float val1 = cosf(radians);
    float val2 = sinf(radians);

    result.M22 = val1;
    result.M23 = val2;
    result.M32 = -val2;
    result.M33 = val1;
    
    return result;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationY(float radians)
{
    Matrix result;
    float val1 = cosf(radians);
    float val2 = sinf(radians);

    result.M11 = val1;
    result.M13 = -val2;
    result.M31 = val2;
    result.M33 = val1;

    return result;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateRotationZ(float radians)
{
    Matrix result;
    float val1 = cosf(radians);
    float val2 = sinf(radians);

    result.M11 = val1;
    result.M12 = val2;
    result.M21 = -val2;
    result.M22 = val1;

    return result;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateFromEulerAngles(const Vector3& angl)
{
    return Matrix::CreateRotationZ(angl.Z) * Matrix::CreateRotationY(angl.Y) * Matrix::CreateRotationX(angl.X);
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateScale(float scalar)
{
    Matrix a;
    a *= scalar;
    a.M44 = 1;
    return a;
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateScale(const Vector3 &scale)
{
    Matrix a;
    a.M11 = scale.X;
    a.M22 = scale.Y;
    a.M33 = scale.Z;
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

_3DRadSpaceDll::Matrix::operator DirectX::XMMATRIX()
{
    return DirectX::XMMATRIX(M11, M12, M13, M14, M21, M22, 23, M24, M31, M32, M33, M34, M41, M42, M43, M44);
}

_3DRadSpaceDll::Matrix _3DRadSpaceDll::Matrix::CreateShadow(const Vector3 &lightDirection, const Plane &plane )
{
    Matrix result;
    float dot = (plane.Normal.X * lightDirection.X) + (plane.Normal.Y * lightDirection.Y) + (plane.Normal.Z * lightDirection.Z);
    float x = -plane.Normal.X;
    float y = -plane.Normal.Y;
    float z = -plane.Normal.Z;
    float d = -plane.Distance;

    result.M11 = (x * lightDirection.X) + dot;
    result.M12 = x * lightDirection.Y;
    result.M13 = x * lightDirection.Z;
    result.M14 = 0;
    result.M21 = y * lightDirection.X;
    result.M22 = (y * lightDirection.Y) + dot;
    result.M23 = y * lightDirection.Z;
    result.M24 = 0;
    result.M31 = z * lightDirection.X;
    result.M32 = z * lightDirection.Y;
    result.M33 = (z * lightDirection.Z) + dot;
    result.M34 = 0;
    result.M41 = d * lightDirection.X;
    result.M42 = d * lightDirection.Y;
    result.M43 = d * lightDirection.Z;
    result.M44 = dot;

    return result;
}