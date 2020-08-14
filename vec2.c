#include "m3d/m3d.h"
#include <math.h>

M3dValue m3dVec2Angle(Vec2 a, Vec2 b)
{
    M3dValue numerator = m3dVec2Dot(a, b);
    M3dValue denominator = m3dVec2Length(a) * m3dVec2Length(b);

    return acos(numerator / denominator);
}

M3dValue m3dVec2Distance(Vec2 a, Vec2 b)
{
    return m3dVec2Length(m3dVec2SubVec2(b, a));
}

M3dValue m3dVec2Dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

M3dValue m3dVec2Length(Vec2 v)
{
    return sqrt(m3dVec2LengthSqr(v));
}

M3dValue m3dVec2LengthSqr(Vec2 v)
{
    return v.x * v.x + v.y * v.y;
}

Vec2 m3dVec2Lerp(Vec2 a, Vec2 b, M3dValue t)
{
    a.x = m3d1DLerp(a.x, b.x, t);
    a.y = m3d1DLerp(a.y, b.y, t);
    return a;
}

Vec2 m3dVec2Max(Vec2 a, Vec2 b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);

    return a;
}

Vec2 m3dVec2Min(Vec2 a, Vec2 b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);

    return a;
}

Vec2 m3dVec2Normalized(Vec2 v)
{
    M3dValue length = m3dVec2Length(v);
    return m3dVec2DivValue(v, length);
}

Vec2 m3dVec2Reflect(Vec2 v, Vec2 n)
{
    M3dValue numerator = m3dVec2Dot(m3dVec2MulValue(v, 2), n);
    Vec2 a = m3dVec2MulValue(n, numerator / m3dVec2LengthSqr(n));

    return m3dVec2SubVec2(v, a);
}

Vec2 m3dVec2Slerp(Vec2 a, Vec2 b, M3dValue t)
{
     M3dValue dot = m3dVec2Dot(a, b);
     dot = m3d1DClamp(dot, -1.0f, 1.0f);
     M3dValue theta = acos(dot)* t;
     Vec2 offset = m3dVec2SubVec2(b, m3dVec2MulValue(a, dot));
     offset = m3dVec2Normalized(offset);
     return m3dVec2AddVec2(m3dVec2MulValue(a, cos(theta)), m3dVec2MulValue(offset, sin(theta)));
}

Vec2 m3dVec2AddVec2(Vec2 a, Vec2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vec2 m3dVec2AddValue(Vec2 a, M3dValue b)
{
    a.x += b;
    a.y += b;
    return a;
}

Vec2 m3dVec2SubVec2(Vec2 a, Vec2 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vec2 m3dVec2SubValue(Vec2 a, M3dValue b)
{
    a.x -= b;
    a.y -= b;
    return a;
}

Vec2 m3dVec2MulVec2(Vec2 a, Vec2 b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

Vec2 m3dVec2MulValue(Vec2 a, M3dValue b)
{
    a.x *= b;
    a.y *= b;
    return a;
}

Vec2 m3dVec2DivVec2(Vec2 a, Vec2 b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

Vec2 m3dVec2DivValue(Vec2 a, M3dValue b)
{
    a.x /= b;
    a.y /= b;
    return a;
}

char m3dVec2Equal(Vec2 a, Vec2 b)
{
    return a.x == b.x && a.y == b.y;
}
