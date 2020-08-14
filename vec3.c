#include "m3d/m3d.h"
#include <math.h>

M3dValue m3dVec3Angle(Vec3 a, Vec3 b)
{
    M3dValue numerator = m3dVec3Dot(a, b);
    M3dValue denominator = m3dVec3Length(a) * m3dVec3Length(b);

    return acos(numerator / denominator);
}

Vec3 m3dVec3Cross(Vec3 a, Vec3 b)
{
    Vec3 res = {0, 0, 0};
    res.x = a.y * b.z - a.z * b.y;
    res.y = a.z * b.x - a.x * b.z;
    res.z = a.x * b.y - a.y * b.x;
    return res;
}

M3dValue m3dVec3Distance(Vec3 a, Vec3 b)
{
    return m3dVec3Length(m3dVec3SubVec3(b, a));
}

M3dValue m3dVec3Dot(Vec3 a, Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

M3dValue m3dVec3Length(Vec3 v)
{
    return sqrt(m3dVec3LengthSqr(v));
}

M3dValue m3dVec3LengthSqr(Vec3 v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

Vec3 m3dVec3Lerp(Vec3 a, Vec3 b, M3dValue t)
{
    a.x = m3d1DLerp(a.x, b.x, t);
    a.y = m3d1DLerp(a.y, b.y, t);
    a.z = m3d1DLerp(a.z, b.z, t);
    return a;
}

Vec3 m3dVec3Max(Vec3 a, Vec3 b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);

    return a;
}

Vec3 m3dVec3Min(Vec3 a, Vec3 b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);

    return a;
}

Vec3 m3dVec3Normalized(Vec3 v)
{
    M3dValue length = m3dVec3Length(v);
    return m3dVec3DivValue(v, length);
}

Vec3 m3dVec3Reflect(Vec3 v, Vec3 n)
{
    M3dValue numerator = m3dVec3Dot(m3dVec3MulValue(v, 2), n);
    Vec3 a = m3dVec3MulValue(n, numerator / m3dVec3LengthSqr(n));

    return m3dVec3SubVec3(v, a);
}

Vec3 m3dVec3Slerp(Vec3 a, Vec3 b, M3dValue t)
{
    M3dValue dot = m3dVec3Dot(a, b);
    dot = m3d1DClamp(dot, -1.0f, 1.0f);
    M3dValue theta = acos(dot)* t;
    Vec3 offset = m3dVec3SubVec3(b, m3dVec3MulValue(a, dot));
    offset = m3dVec3Normalized(offset);
    return m3dVec3AddVec3(m3dVec3MulValue(a, cos(theta)), m3dVec3MulValue(offset, sin(theta)));
}

Vec3 m3dVec3AddVec3(Vec3 a, Vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vec3 m3dVec3AddValue(Vec3 a, M3dValue b)
{
    a.x += b;
    a.y += b;
    a.z += b;
    return a;
}

Vec3 m3dVec3SubVec3(Vec3 a, Vec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vec3 m3dVec3SubValue(Vec3 a, M3dValue b)
{
    a.x -= b;
    a.y -= b;
    a.z -= b;
    return a;
}

Vec3 m3dVec3MulVec3(Vec3 a, Vec3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

Vec3 m3dVec3MulValue(Vec3 a, M3dValue b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

Vec3 m3dVec3DivVec3(Vec3 a, Vec3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

Vec3 m3dVec3DivValue(Vec3 a, M3dValue b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

char m3dVec3Equal(Vec3 a, Vec3 b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}
