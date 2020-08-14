#include "m3d/m3d.h"
#include <math.h>
#include <stdint.h>

static void setAllZeroInternal(Mat4x4 *v)
{
    for(int i = 0; i < 4; i++)
    {
         for(int j = 0; j < 4; j++)
        {
            v->m[i][j] = 0;
        }
    }
}

Mat4x4 m3dMat4x4InitIdentity()
{
    Mat4x4 res;

    setAllZeroInternal(&res);

    // set diagonal to 1s
    for(int i = 0; i < 4; i++)
    {
        res.m[i][i] = 1;
    }

    return res;
}

Mat4x4 m3dMat4x4InitOrtho(M3dValue r, M3dValue l, M3dValue t, M3dValue b, M3dValue n, M3dValue f)
{
    Mat4x4 res;
    setAllZeroInternal(&res);

    M3dValue rml = 1.0 / (r - l);
    M3dValue tmb = 1.0 / (t - b);
    M3dValue fmn = 1.0 / (f - n);

    res.m[0][0] = 2.0 * rml;
    res.m[1][1] = 2.0 * tmb;
    res.m[2][2] = 2.0 * fmn;
    res.m[3][3] = 1.0;
    res.m[0][3] = -(r + l) * rml;
    res.m[1][3] = -(t + b) * tmb;
    res.m[2][3] = -(f + n) * fmn;

    return res;
}

Mat4x4 m3dMat4x4InitOrthoCentered(M3dValue w, M3dValue h, M3dValue n, M3dValue f)
{
    Mat4x4 res;
    setAllZeroInternal(&res);

    M3dValue fmn = 1.0 / (f - n);

    res.m[0][0] = 2.0 / w;
    res.m[1][1] = 2.0 / h;
    res.m[2][2] = -2.0 * fmn;
    res.m[3][3] = 1.0;
    res.m[2][3] = -(f + n) * fmn;

    return res;
}

Mat4x4 m3dMat4x4InitPerspective(M3dValue w, M3dValue h, M3dValue fov, M3dValue n, M3dValue f)
{
    Mat4x4 res;
    setAllZeroInternal(&res);

    M3dValue cotFov = 1.0 / tan(fov / 2.0);
    M3dValue fmn = 1.0 / (f - n);
    M3dValue aspect = w / h;

    res.m[0][0] = cotFov / aspect;
    res.m[1][1] = cotFov;
    res.m[2][2] = -(f + n) * fmn;
    res.m[2][3] = -2 * (f * n) * fmn;
    res.m[3][2] = -1.0;

    return res;

}

Mat4x4 m3dMat4x4InverseHomogeneous(Mat4x4 mat)
{
    return m3dMat4x4InitIdentity();
}

Mat4x4 m3dMat4x4Rotate(Mat4x4 *m, Quat r)
{
    // precalc most parts
    M3dValue i2 = r.i * r.i * 2.0;
    M3dValue j2 = r.j * r.j * 2.0;
    M3dValue k2 = r.k * r.k * 2.0;

    M3dValue ij = r.i * r.j * 2.0;
    M3dValue jk = r.j * r.k * 2.0;
    M3dValue ik = r.i * r.k * 2.0;

    M3dValue iw = r.i * r.w * 2.0;
    M3dValue jw = r.j * r.w * 2.0;
    M3dValue kw = r.k * r.w * 2.0;

    m->m[0][0] = 1 - j2 - k2;   m->m[0][1] = ij - kw;       m->m[0][2] = ik + jw;
    m->m[1][0] = ij + kw;       m->m[1][1] = 1 - i2 - k2;   m->m[1][2] = jk - iw;
    m->m[2][0] = ik - jw;       m->m[2][1] = jk + iw;       m->m[2][2] = 1 - i2 - j2;

    return *m;
}

Mat4x4 m3dMat4x4RotateY(Mat4x4 *m, M3dValue r)
{
    M3dValue sinTheta = sin(r);
    M3dValue cosTheta = cos(r);

    m->m[0][0] = cosTheta;
    m->m[0][2] = sinTheta;
    m->m[2][0] = -sinTheta;
    m->m[2][2] = cosTheta;

    return *m;
}

Mat4x4 m3dMat4x4Scale(Mat4x4 *m, Vec3 s)
{
    m->m[0][0] = s.x;
    m->m[1][1] = s.y;
    m->m[2][2] = s.z;

    return *m;
}

Mat4x4 m3dMat4x4Translate(Mat4x4 *m, Vec3 t)
{
    m->m[0][3] = t.x;
    m->m[1][3] = t.y;
    m->m[2][3] = t.z;

    return *m;
}

Mat4x4 m3dMat4x4FromMat3x3(Mat3x3 m)
{
    Mat4x4 res;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            res.m[i][j] = m.m[i][j];
        }

        res.m[3][i] = 0;
        res.m[i][3] = 0;
    }

    res.m[3][3] = 1;

    return res;
}

Mat4x4 m3dMat4x4MulMat4x4(Mat4x4 a, Mat4x4 b)
{
    Mat4x4 res;

    for (uint8_t i = 0 ; i < 4 ; i++ )
    {
        for (uint8_t j = 0 ; j < 4 ; j++ )
        {
            M3dValue sum = 0;
            for (uint8_t k = 0 ; k < 4 ; k++ )
            {
                sum += a.m[i][k] * b.m[k][j];
            }

            res.m[i][j] = sum;
        }
    }

    return res;
}

Vec4 m3dMat4x4MulVec4(Mat4x4 a, Vec4 b)
{
    Vec4 res;

    res.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z + a.m[0][3] * b.w;
    res.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z + a.m[1][3] * b.w;
    res.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z + a.m[2][3] * b.w;
    res.w = a.m[3][0] * b.x + a.m[3][1] * b.y + a.m[3][2] * b.z + a.m[3][3] * b.w;

    return res;
}
