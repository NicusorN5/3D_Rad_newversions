#include "pch.h"
#include "Quaternion.h"

_3DRadSpaceDll::Quaternion _3DRadSpaceDll::Quaternion::FromEuler(const Vector3 &vector)
{
    float halfRoll = vector.Z * 0.5f;
    float halfPitch = vector.X * 0.5f;
    float halfYaw = vector.Y * 0.5f;

    float sinRoll = sinf(halfRoll);
    float cosRoll = cosf(halfRoll);
    float sinPitch = sinf(halfPitch);
    float cosPitch = cosf(halfPitch);
    float sinYaw = sinf(halfYaw);
    float cosYaw = cosf(halfYaw);

    Quaternion result;

    result.X = (cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll);
    result.Y = (sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll);
    result.Z = (cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll);
    result.W = (cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll);

    return result;
}

_3DRadSpaceDll::Vector3 _3DRadSpaceDll::Quaternion::EulerFromQuaternion(const Quaternion &q)
{
    Vector3 angles;

    // roll (x-axis rotation)
    float sinr_cosp = 2 * (q.W * q.X + q.Y * q.Z);
    float cosr_cosp = 1 - 2 * (q.X * q.X + q.Y * q.Y);
    angles.Z = atan2f(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    float sinp = 2 * (q.W * q.Y - q.Z * q.X);
    if (std::abs(sinp) >= 1)
        angles.X = copysignf(3.1415926f / 2, sinp); // use 90 degrees if out of range
    else
        angles.X = asinf(sinp);

    // yaw (z-axis rotation)
    float siny_cosp = 2 * (q.W * q.Z + q.X * q.Y);
    float cosy_cosp = 1 - 2 * (q.Y * q.Y + q.Z * q.Z);
    angles.Y = atan2f(siny_cosp, cosy_cosp);

    return angles;
}

_3DRadSpaceDll::Quaternion _3DRadSpaceDll::Quaternion::Multiply(const Quaternion &quaternion1,const Quaternion &quaternion2)
{
    Quaternion result;
    float x = quaternion1.X;
    float y = quaternion1.Y;
    float z = quaternion1.Z;
    float w = quaternion1.W;
    float num4 = quaternion2.X;
    float num3 = quaternion2.Y;
    float num2 = quaternion2.Z;
    float num = quaternion2.W;
    float num12 = (y * num2) - (z * num3);
    float num11 = (z * num4) - (x * num2);
    float num10 = (x * num3) - (y * num4);
    float num9 = ((x * num4) + (y * num3)) + (z * num2);
    result.X = ((x * num) + (num4 * w)) + num12;
    result.Y = ((y * num) + (num3 * w)) + num11;
    result.Z = ((z * num) + (num2 * w)) + num10;
    result.W = (w * num) - num9;
    return result;
}

void _3DRadSpaceDll::Quaternion::Normalize()
{
    float num = 1.0f / ((float)sqrtf((X * X) + (Y * Y) + (Z * Z) + (W * W)));
    this->X *= num;
    this->Y *= num;
    this->Z *= num;
    this->W *= num;
}
