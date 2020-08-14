#include "m3d/m3d.h"
#include <math.h>
#include <stdint.h>

static void setAllZeroInternal(Mat3x3 *v)
{
    for(int i = 0; i < 3; i++)
    {
         for(int j = 0; j < 3; j++)
        {
            v->m[i][j] = 0;
        }
    }
}

Mat3x3 m3dMat3x3InitIdentity()
{
    Mat3x3 res;

    setAllZeroInternal(&res);

    // set diagonal to 1s
    for(int i = 0; i < 3; i++)
    {
        res.m[i][i] = 1;
    }

    return res;
}

Mat3x3 m3dMat3x3InitOrtho(M3dValue r, M3dValue l, M3dValue t, M3dValue b)
{
    Mat3x3 res;
    setAllZeroInternal(&res);

    M3dValue rml = 1.0 / (r - l);
    M3dValue tmb = 1.0 / (t - b);

    res.m[0][0] = 2.0 * rml;
    res.m[1][1] = 2.0 * tmb;
    res.m[2][2] = 1.0;
    res.m[0][2] = -(r + l) * rml;
    res.m[1][2] = -(t + b) * tmb;

    return res;
}

Mat3x3 m3dMat3x3InitOrthoCentered(M3dValue w, M3dValue h)
{
    Mat3x3 res;
    setAllZeroInternal(&res);

    res.m[0][0] = 2.0 / w;
    res.m[1][1] = 2.0 / h;
    res.m[2][2] = 1.0;

    return res;
}

Mat3x3 m3dMat3x3InitRotationFromQuat(Quat quat)
{
    Mat3x3 res;

    // precalc most parts
    M3dValue i2 = quat.i * quat.i * 2.0;
    M3dValue j2 = quat.j * quat.j * 2.0;
    M3dValue k2 = quat.k * quat.k * 2.0;

    M3dValue ij = quat.i * quat.j * 2.0;
    M3dValue jk = quat.j * quat.k * 2.0;
    M3dValue ik = quat.i * quat.k * 2.0;

    M3dValue iw = quat.i * quat.w * 2.0;
    M3dValue jw = quat.j * quat.w * 2.0;
    M3dValue kw = quat.k * quat.w * 2.0;

    res.m[0][0] = 1 - j2 - k2;   res.m[0][1] = ij - kw;       res.m[0][2] = ik + jw;
    res.m[1][0] = ij + kw;       res.m[1][1] = 1 - i2 - k2;   res.m[1][2] = jk - iw;
    res.m[2][0] = ik - jw;       res.m[2][1] = jk + iw;       res.m[2][2] = 1 - i2 - j2;

    return res;
}

Mat3x3 m3dMat3x3Rotate(Mat3x3 *m, M3dValue r)
{
    M3dValue cosTheta = cos(r);
    M3dValue sinTheta = sin(r);

    m->m[0][0] = cosTheta;
    m->m[0][1] = -sinTheta;
    m->m[1][0] = sinTheta;
    m->m[1][1] = cosTheta;

    return *m;
}

Mat3x3 m3dMat3x3Scale(Mat3x3 *m, Vec2 s)
{
    m->m[0][0] = s.x;
    m->m[1][1] = s.y;

    return *m;
}

Mat3x3 m3dMat3x3Translate(Mat3x3 *m, Vec2 t)
{
    m->m[0][2] = t.x;
    m->m[1][2] = t.y;

    return *m;
}

Mat3x3 m3dMat3x3FromMat4x4(Mat4x4 m)
{
    Mat3x3 res;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            res.m[i][j] = m.m[i][j];
        }
    }

    return res;
}

Mat3x3 m3dMat3x3MulMat3x3(Mat3x3 a, Mat3x3 b)
{
    Mat3x3 res;

    for (uint8_t i = 0 ; i < 3 ; i++ )
    {
        for (uint8_t j = 0 ; j < 3 ; j++ )
        {
            M3dValue sum = 0;
            for (uint8_t k = 0 ; k < 3 ; k++ )
            {
                sum += a.m[i][k] * b.m[k][j];
            }

            res.m[i][j] = sum;
        }
    }

    return res;
}

Vec3 m3dMat3x3MulVec3(Mat3x3 a, Vec3 b)
{
    Vec3 res;

    res.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z;
    res.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z;
    res.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z;

    return res;
}
