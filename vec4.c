#include "m3d/m3d.h"

Vec4 m3dVec4AddVec4(Vec4 a, Vec4 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

Vec4 m3dVec4AddValue(Vec4 a, M3dValue b)
{
    a.x += b;
    a.y += b;
    a.z += b;
    a.w += b;
    return a;
}

Vec4 m3dVec4SubVec4(Vec4 a, Vec4 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

Vec4 m3dVec4SubValue(Vec4 a, M3dValue b)
{
    a.x -= b;
    a.y -= b;
    a.z -= b;
    a.w -= b;
    return a;
}

Vec4 m3dVec4MulVec4(Vec4 a, Vec4 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

Vec4 m3dVec4MulValue(Vec4 a, M3dValue b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    a.w *= b;
    return a;
}

Vec4 m3dVec4DivVec4(Vec4 a, Vec4 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

Vec4 m3dVec4DivValue(Vec4 a, M3dValue b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
    a.w /= b;
    return a;
}

char m3dVec4Equal(Vec4 a, Vec4 b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}
