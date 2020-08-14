#include "m3d/m3d.h"
#include <math.h>

//https://www.mathworks.com/matlabcentral/answers/415936-angle-between-2-quaternions
M3dValue m3dQuatAngle(Quat a, Quat b)
{
    return 2 * acos(m3dQuatMulQuat(m3dQuatConjugate(a), b).w);
}

//https://stackoverflow.com/questions/12435671/quaternion-lookat-function
//https://gamedev.stackexchange.com/questions/15070/orienting-a-model-to-face-a-target
Quat m3dQuatAngleVec3(Vec3 a, Vec3 b, Vec3 up)
{
    float dot = m3dVec3Dot(a, b);
    // test for dot -1
    if(fabs(dot + 1.0f) < 0.000001f)
    {
        // vector a and b point exactly in the opposite direction,
        // so it is a 180 degrees turn around the up-axis
        return m3dQuatAngleAxis(180.0f * TO_RADS, up);
    }
    // test for dot 1
    else if(fabs(dot - 1.0f) < 0.000001f)
    {
        // vector a and b point exactly in the same direction
        // so we return the identity quaternion
        return (Quat){0.0f, 0.0f, 0.0f, 1.0f};
    }

    float rotAngle = acos(dot);
    Vec3 rotAxis = m3dVec3Cross(a, b);
    rotAxis = m3dVec3Normalized(rotAxis);
    return m3dQuatAngleAxis(rotAngle, rotAxis);
}

Quat m3dQuatAngleAxis(M3dValue r, Vec3 a)
{
    Quat res;
    res.i = a.x * sin(r / 2.0);
    res.j = a.y * sin(r / 2.0);
    res.k = a.z * sin(r / 2.0);
    res.w = cos(r / 2.0);

    return res;
}

Quat m3dQuatConjugate(Quat v)
{
    v.i = -v.i;
    v.j = -v.j;
    v.k = -v.k;
    return v;
}

Vec3 m3dQuatEuler(Quat v)
{
    M3dValue i2 = v.i * v.i;
    M3dValue j2 = v.j * v.j;
    M3dValue k2 = v.k * v.k;

    Vec3 res;
    res.x = atan2(2 * (v.w * v.i + v.j * v.k), 1 - 2 * (i2 + j2));
    res.y = asin(2 * (v.w * v.j - v.k * v.i));
    res.z = atan2(2 * (v.w * v.k + v.i * v.j), 1 - 2 * (j2 + k2));

    return res;
}

Quat m3dQuatFace(Vec3 dir, Vec3 up)
{
    return m3dQuatAngleVec3((Vec3){0.0f, 0.0f, 1.0f}, dir, up);
}

M3dValue m3dQuatLength(Quat v)
{
    M3dValue res = sqrt(v.i * v.i + v.j * v.j + v.k * v.k + v.w * v.w);

    return res;
}

Vec3 m3dQuatRotateVec3(Quat a, Vec3 b)
{
    Quat P = {b.x, b.y, b.z, 0};

    Quat temp = m3dQuatMulQuat(m3dQuatMulQuat(a, P), m3dQuatConjugate(a));

    return (Vec3){temp.i, temp.j, temp.k};
}

Quat m3dQuatNormalized(Quat v)
{
    M3dValue length = m3dQuatLength(v);
    v.i /= length;
    v.j /= length;
    v.k /= length;
    v.w /= length;
    return v;
}

Quat m3dQuatSlerp(Quat a, Quat b, M3dValue t)
{
    Quat res;

    M3dValue cosHalfTheta = a.w * b.w + a.i * b.i + a.j * b.j + a.k * b.k;
	// if qa=qb or qa=-qb then theta = 0 and we can return qa
	if (abs(cosHalfTheta) >= 1.0)
    {
		return a;
	}
	// Calculate temporary values.
	M3dValue halfTheta = acos(cosHalfTheta);
	M3dValue sinHalfTheta = sqrt(1.0 - cosHalfTheta*cosHalfTheta);
	// if theta = 180 degrees then result is not fully defined
	// we could rotate around any axis normal to qa or qb
	if (fabs(sinHalfTheta) < 0.001)
	{
	    return m3dQuatAddQuat(m3dQuatMulValue(a, 0.5), m3dQuatMulValue(b, 0.5));
	}

	//calculate Quaternion.
	res = m3dQuatMulValue(a, sin((1 - t) * halfTheta));
	res = m3dQuatAddQuat(res, m3dQuatMulValue(b, sin(t * halfTheta)));
	res = m3dQuatDivValue(res, sin(halfTheta));

	return res;
}

Quat m3dQuatAddQuat(Quat a, Quat b)
{
    a.i += b.i;
    a.j += b.j;
    a.k += b.k;
    a.w += b.w;

    return a;
}

Quat m3dQuatSubQuat(Quat a, Quat b)
{
    a.i -= b.i;
    a.j -= b.j;
    a.k -= b.k;
    a.w -= b.w;

    return a;
}

Quat m3dQuatMulQuat(Quat a, Quat b)
{
    Quat res;

    res.i = a.w * b.i + a.i * b.w + a.j * b.k - a.k * b.j;
    res.j = a.w * b.j - a.i * b.k + a.j * b.w + a.k * b.i;
    res.k = a.w * b.k + a.i * b.j - a.j * b.i + a.k * b.w;
    res.w = a.w * b.w - a.i * b.i - a.j * b.j - a.k * b.k;

    //res.i = a.i * b.w + a.w * b.i + a.j * b.k - a.k * b.j;
    //res.j = a.j * b.w + a.w * b.j + a.k * b.i - a.i * b.k;
    //res.k = a.k * b.w + a.w * b.k + a.i * b.j - a.j * b.i;
    //res.w = a.w * b.w - a.i * b.i - a.j * b.j - a.k * b.k;

    return res;
}

Quat m3dQuatMulValue(Quat a, M3dValue b)
{
    a.i *= b;
    a.j *= b;
    a.k *= b;
    a.w *= b;

    return a;
}

Quat m3dQuatDivValue(Quat a, M3dValue b)
{
    a.i /= b;
    a.j /= b;
    a.k /= b;
    a.w /= b;

    return a;
}

char m3dQuatEqual(Quat a, Quat b)
{
    return a.i == b.i && a.j == b.j && a.k == b.k && a.w == b.w;
}
